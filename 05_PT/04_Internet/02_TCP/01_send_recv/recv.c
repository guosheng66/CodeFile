#include "head.h"

int main(int argc, char const *argv[])
{
    int ret = 0;
    int sockfd = 0;
    int confd = 0;
    ssize_t nsize = 0;
    struct sockaddr_in recvaddr;
    char tmpbuff[1024] = {0};

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sockfd)
    {
        perror("fail to socket");
        return -1;
    }

    recvaddr.sin_family = AF_INET;
    recvaddr.sin_port = htons(50000);
    recvaddr.sin_addr.s_addr = inet_addr("192.168.3.255");
    if (-1 == ret)
    {
        perror("fail to bind");
        return -1;
    }

    ret = listen(sockfd, 10);
    if (-1 == ret)
    {
        perror("fail to listen");
        return -1;
    }

    confd = accept(sockfd, NULL, NULL);
    if (-1 == confd)
    {
        perror("fail to accept");
        return -1;
    }

    nsize = recv(confd, tmpbuff, sizeof(tmpbuff), 0);
    if (-1 == nsize)
    {
        perror("fail to recv");
        return -1;
    }

    printf("%s\n", tmpbuff);

    sprintf(tmpbuff, "%s ---- echo", tmpbuff);
    nsize = send(confd, tmpbuff, strlen(tmpbuff), 0);
    if (-1 == nsize)
    {
        perror("fail to send");
        return -1;
    }

    close(confd);
    close(sockfd);

    return 0;
}
