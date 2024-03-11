#include "head.h"

int TcpClientCreateConnection(char *pIP, int port)
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
    ret = connect(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    if (-1 == ret)
    {
        perror("connect error");
        return -1;
    }

    return sockfd;
}

int TcpHandleFun(int sockfd)
{
    char tmpbuff[1024] = {"hello world"};
    ssize_t nsize = 0;
    int cnt = 0;

    while (1)
    {
        sprintf(tmpbuff, "hello world ---- %d\n", cnt);
        cnt++;
        nsize = send(sockfd, tmpbuff, strlen(tmpbuff), 0);
        if (-1 == nsize)
        {
            perror("send error");
            return -1;
        }

        memset(tmpbuff, 0, sizeof(tmpbuff));
        nsize = recv(sockfd, tmpbuff, sizeof(tmpbuff), 0);
        if (-1 == nsize)
        {
            perror("fail to recv");
            return -1;
        }

        printf("RECV: %s\n", tmpbuff);
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    int sockfd = 0;

    sockfd = TcpClientCreateConnection("192.168.3.108", 50000);
    if (-1 == sockfd)
    {
        printf("create connection failed\n");
        return -1;
    }

    TcpHandleFun(sockfd);

    close(sockfd);

    return 0;
}
