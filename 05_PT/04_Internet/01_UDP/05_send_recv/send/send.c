#include "head.h"

int main(int argc, char const *argv[])
{
    int sockfd = 0;
    char tmpbuff[4096] = {"hello world"};
    struct sockaddr_in destaddr;
    ssize_t nsize = 0;
    int on = 1;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (-1 == sockfd)
    {
        perror("fail to socket");
        return -1;
    }

    setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR | SO_BROADCAST,&on,sizeof(on));

    destaddr.sin_family = AF_INET;
    destaddr.sin_port = htons(50000);
    destaddr.sin_addr.s_addr = inet_addr("192.168.3.255");

    nsize = sendto(sockfd, tmpbuff, strlen(tmpbuff), 0, (struct sockaddr*)&destaddr, sizeof(destaddr));
    if (-1 == nsize)
    {
        perror("fail to sendto");
        return -1;
    }

    printf("发送成功%ld个字符\n", nsize);

    close(sockfd);

    return 0;
}
