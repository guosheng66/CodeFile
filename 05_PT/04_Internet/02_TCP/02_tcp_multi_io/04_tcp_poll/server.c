#include "head.h"

/* 网络处理函数 */
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
        perror("send error");
        return -1;
    }

    return nsize;
}

int TcpServerCreateListenSocket(char *pIP, int port)
{
    int sockfd = 0;
    int ret = 0;
    struct sockaddr_in seraddr;

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

int InitPollFds(struct pollfd *pfds, int maxlen)
{
    int i = 0;

    for (i = 0; i < maxlen; i++)
    {
        pfds[i].fd = -1;
    }

    return 0;
}

int AddPollFd(struct pollfd *pfds, int maxlen, int fd, short env)
{
    int i = 0;

    for (i = 0; i < maxlen; i++)
    {
        if (pfds[i].fd == -1)
        {
            pfds[i].fd = fd;
            pfds[i].events = env;
            break;
        }
    }

    return 0;
}

int RemovePollFd(struct pollfd *pfds, int maxlen, int fd)
{
    int i = 0;

    for (i = 0; i < maxlen; i++)
    {
        if (pfds[i].fd == fd)
        {
            pfds[i].fd = -1;
        }
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    int sockfd = 0;
    int ret = 0;
    int confd = 0;
    int nready = 0;
    int i = 0;
    struct pollfd fds[1024];
    
    /* 创建TCP服务器端监听套接字 */
    sockfd = TcpServerCreateListenSocket("192.168.3.108", 50000);
    if (-1 == sockfd)
    {
        fprintf(stderr, "create tcp server socket failed\n");
        return -1;
    }

    InitPollFds(fds, 1024);
    AddPollFd(fds, 1024, sockfd, POLLIN);

    while (1)
    {
        nready = poll(fds, 1024, -1);
        if (-1 == nready)
        {
            perror("fail to poll");
            return -1;
        }

        for (i = 0; i < 1024; i++)
        {
            if (fds[i].fd == -1)
            {
                continue;
            }

            if (fds[i].revents & POLLIN && fds[i].fd == sockfd)
            {
                confd = accept(sockfd, NULL, NULL);
                if (-1 == confd)
                {
                    perror("fail to accept");
                    RemovePollFd(fds, 1024, sockfd);
                    close(sockfd);
                    continue;
                }

                AddPollFd(fds, 1024, confd, POLLIN);
            }
            else if (fds[i].revents * POLLIN && fds[i].fd != sockfd)
            {
                ret = TcpHandleFun(fds[i].fd);
                if (-1 == ret)
                {
                    printf("客户端异常断开\n");
                    close(fds[i].fd);
                    RemovePollFd(fds, 10242, fds[i].fd);
                    continue;
                }
                else if (0 == ret)
                {
                    printf("客户端断开\n");
                    close(fds[i].fd);
                    RemovePollFd(fds, 1024, fds[i].fd);
                    continue;
                }
            }
        }
    }
    
    return 0;
}
