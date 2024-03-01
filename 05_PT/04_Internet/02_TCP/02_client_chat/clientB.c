#include "head.h"

/* TCP服务器创建监听套接字 */
int TcpServerCreateListenSocket(char *pip, int port)
{
    int sockfd = 0;
    struct sockaddr_in seraddr;
    int ret = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sockfd)
    {
        return -1;
    }

    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(50000);
    seraddr.sin_addr.s_addr = inet_addr("192.168.3.108");
    ret = bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    if (-1 == ret)
    {
        return -1;
    }

    ret = listen(sockfd, 10);
    if (-1 == ret)
    {
        return -1;
    }

    return sockfd;
}

int AddEpollFd(int epfd, int fd, uint32_t env)
{
    struct epoll_event tmpenv;
    int ret = 0;

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
        perror("fail  to epoll_ctl");
        return -1;
    }
}

int TcpHandleFun(int sockfd)
{
    int epfd = 0;
    int nready = 0;
    struct epoll_event retenv[2];
    int i = 0;
    ssize_t nsize = 0;
    char tmpbuff[4096] = {0};

    epfd = epoll_create(2);
    if (-1 == epfd)
    {
        perror("fail to epoll_create");
        return -1;
    }

    AddEpollFd(epfd, sockfd, EPOLLIN);
    AddEpollFd(epfd, 0, EPOLLIN);

    while (1)
    {
        nready = epoll_wait(epfd, retenv, 2, -1);
        if (-1 == nready)
        {
            perror("fail to epoll_wait");
            return -1;
        }

        for (i = 0; i < nready; i++)
        {
            if (retenv[i].data.fd == sockfd)
            {
                memset(tmpbuff, 0, sizeof(tmpbuff));
                nsize = recv(sockfd, tmpbuff, sizeof(tmpbuff), 0);
                if (nsize <= 0)
                {
                    RemoveEpollFd(epfd, retenv[i].data.fd);
                    close(retenv[i].data.fd);
                    continue;
                }

                printf("Recv:%s\n", tmpbuff);
            }
            else if (retenv[i].data.fd == 0)
            {
                memset(tmpbuff, 0, sizeof(tmpbuff));
                gets(tmpbuff);
                nsize = send(sockfd, tmpbuff, strlen(tmpbuff), 0);
                if (nsize == -1)
                {
                    RemoveEpollFd(epfd, retenv[i].data.fd);
                    close(retenv[i].data.fd);
                    continue;
                }
            }
        }
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    int sockfd = 0;
    int confd = 0;

    sockfd = TcpServerCreateListenSocket("192.168.3.108", 50000);
    if (-1 == sockfd)
    {
        printf("Create Connection failed\n");
        return -1;
    }

    confd = accept(sockfd, NULL, NULL);
    if (-1 == confd)
    {
        perror("failt to accept");
        return -1;
    }

    TcpHandleFun(confd);
    
    close(confd);
    close(sockfd);
    
    return 0;
}
