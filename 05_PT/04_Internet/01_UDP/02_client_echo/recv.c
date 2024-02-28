#include "head.h"

int main(int argc, char const *argv[])
{
    int ret = 0;
    int sockfd = 0;
    ssize_t nsize = 0;
    char tmpbuff[1024] = {0};
    struct sockaddr_in recvaddr;
    struct sockaddr_in sendaddr;
    socklen_t addrlen = sizeof(sendaddr);

    /* socket */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (-1 == sockfd)
    {
        perror("fail to socket");
        return -1;
    }

    /* bind */
    recvaddr.sin_family =AF_INET;
    recvaddr.sin_port = htons(50000);
    recvaddr.sin_addr.s_addr = inet_addr("192.168.3.255");
    ret = bind(sockfd, (struct sockaddr *)&recvaddr, sizeof(recvaddr));
    if (-1 == ret)
    {
        perror("fail to bind");
        return -1;
    }

    /* recvfrom */
    nsize = recvfrom(sockfd, tmpbuff, sizeof(tmpbuff), 0, (struct sockaddr *)&sendaddr, &addrlen);    if (-1 == nsize)
    {
        perror("fail to recvfrom");
        return -1;
    }

    printf("%s:%d->%s\n", inet_ntoa(sendaddr.sin_addr), ntohs(sendaddr.sin_port), tmpbuff);

    /* sendto */
    sprintf(tmpbuff, "%s ---- echo", tmpbuff);
    nsize = sendto(sockfd, tmpbuff, strlen(tmpbuff), 0, (struct sockaddr*)&sendaddr, sizeof(sendaddr));
    if (-1 == nsize)
    {
        perror("fail to sendto");
        return -1;
    }

    close(sockfd);

    return 0;
}
