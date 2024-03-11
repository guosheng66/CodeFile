#include "head.h"

#define EPOLL_MAX_CLIENT_NUM 1024

/*网络处理函数 */
int TcpHandleFun(int confd)
{
    char tmpbuff[1024] = {0};
    ssize_t nsize = 0;

    memset(tmpbuff, 0, sizeof(tmpbuff));
    nsize = recv(confd, tmpbuff, sizeof(tmpbuff), 0);
    if (-1 == nsize)
    {
        perror("recv error");
        return -1;       
    }
    else if (0 == nsize)
    {
        return 0;
    }

    sprintf(tmpbuff, "%s ---- echo", tmpbuff);

    nsize = send(confd, tmpbuff, strlen(tmpbuff), 0);
    if (-1 == nsize)
    {
        return -1;
    }

    return nsize;
}

/* TCP服务器创建监听套接字 */
int TcpServerCreateListenSocket(char *pIP, int port)
{
    int sockfd = 0;
    struct sockaddr_in seraddr;
    int ret = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sockfd)
    {
        perror("socket error");
        return -1;
    }

    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(port);
    seraddr.sin_addr.s_addr = inet_addr(pIP);
    ret = bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    if (-1 == ret)
    {
        perror("bind error");
        return -1;
    }

    ret = listen(sockfd, 10);
    if (-1 == ret)
    {
        perror("listen error");
        return -1;
    }

    return sockfd;
}

int AddEpollFd(int epfd, int fd, uint32_t env)
{
    int ret = 0;
    struct epoll_event tmpenv;

    tmpenv.events = env;
    tmpenv.data.fd = fd;

    ret = epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &tmpenv);
    if (-1 == ret)
    {
        perror("fail to epoll_ctl");
        return -1;
    }

    return 0;
}

int RemoveEpollFd(int epfd, int fd)
{
    int ret = 0;

    ret = epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
    if (-1 == ret)
    {
        perror("faill to epoll_ctl");
        return -1;
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    int sockfd = 0;
    int ret = 0;
    int confd = 0;
    int epfd = 0;
    int nready = 0;
    int i = 0;
    struct epoll_event retenv[EPOLL_MAX_CLIENT_NUM];

    sockfd = TcpServerCreateListenSocket("192.168.3.108", 50000);
    if (-1 == sockfd)
    {
        fprintf(stderr, "create tcp server socket failed\n");
        return -1;
    }

    epfd = epoll_create(EPOLL_MAX_CLIENT_NUM);
    if (-1 == epfd)
    {
        perror("fail to epoll_create");
        return -1;
    }

    AddEpollFd(epfd, sockfd, EPOLLIN);

    while (1)
    {
        nready = epoll_wait(epfd, retenv, EPOLL_MAX_CLIENT_NUM, -1);
        if (-1 == nready)
        {
            perror("epoll_wait error");
            return -1;
        }

        for (i = 0; i < nready; i++)
        {
            if (retenv[i].data.fd == sockfd)
            {
                confd = accept(sockfd, NULL, NULL);
                if (-1 == confd)
                {
                    perror("accept error");
                    RemoveEpollFd(epfd, sockfd);
                    close(sockfd);
                    continue;
                }

                AddEpollFd(epfd, confd, EPOLLIN);
            }
            else if (retenv[i].data.fd != sockfd)
            {
                ret = TcpHandleFun(retenv[i].data.fd);
                if (-1 == ret)
                {
                    printf("客户端异常断开\n");
                    RemoveEpollFd(epfd, retenv[i].data.fd);
                    close(retenv[i].data.fd);
                    continue;
                }
                else if (0 == ret)
                {
                    printf("客户端断开\n");
                    RemoveEpollFd(epfd, retenv[i].data.fd);
                    close(retenv[i].data.fd);
                    continue;
                }
            }
        }
    }

    
    return 0;
}
