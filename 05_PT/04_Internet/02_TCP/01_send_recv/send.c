#include "head.h"

int main(int argc, char const *argv[])
{
    int ret = 0;
    int sockfd = 0;
    ssize_t nsize = 0;
    char tmpbuff[1024] = {0};
    struct sockaddr_in recvaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sockfd)
    {
        perror("fail to socket");
        return -1;
    }

    recvaddr.sin_family = AF_INET;
    recvaddr.sin_port = htons(50000);
    recvaddr.sin_addr.s_addr = inet_addr("192.168.3.255");
    ret = connect(sockfd, (struct sockaddr*)&recvaddr, sizeof(recvaddr));
    if (-1 == ret)
    {
        perror("fail to connect");
        return -1;
    }    

    sprintf(tmpbuff, "hello world");
    nsize = send(sockfd, tmpbuff, strlen(tmpbuff), 0);
    if (-1 == nsize)
    {
        perror("fail to send");
        return -1;
    }

    memset(tmpbuff, 0, sizeof(tmpbuff));
    nsize = recv(sockfd, tmpbuff, sizeof(tmpbuff), 0);
    if (-1 == nsize)
    {
        perror("fail to recv");
        return -1;
    }

    printf("RECV:%s\n", tmpbuff);

    close(sockfd);

    return 0;
}
