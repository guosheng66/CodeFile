#include "head.h"

int main(int argc, char const *argv[])
{
    int ret = 0;
    int sockfd = 0;
    ssize_t nsize = 0;
    struct sockaddr_in addr;
    char tmpbuff[4096] = {0};
    int on = 1;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (-1 == sockfd)
    {
        perror("fail to socket");
        return -1;
    }

    // setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR | SO_BROADCAST,&on,sizeof(on));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(50000);
    addr.sin_addr.s_addr = inet_addr("192.168.3.255");
    
    ret = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if (-1 == ret)
    {
        perror("fail to bind");
        return -1;
    }

    nsize = recvfrom(sockfd, tmpbuff, sizeof(tmpbuff), 0, NULL, NULL);
    if (-1 == nsize)
    {
        perror("fail to recvfrom");
        return -1;
    }

    printf("RECV:%s\n", tmpbuff);

    close(sockfd);
    
    return 0;
}
