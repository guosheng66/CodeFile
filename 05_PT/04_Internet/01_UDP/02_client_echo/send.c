#include "head.h"

int main(int argc, char const *argv[])
{
    ssize_t nsize = 0;
    int sockfd = 0;
    char tmpbuff[4096] = {0};
    struct sockaddr_in recvaddr;
    int on = 1;

    /* socket */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (-1 == sockfd)
    {
        perror("fail to socket");
        return -1;
    }

    setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR | SO_BROADCAST,&on,sizeof(on));

    printf("请输入要发送文件的名称：");
    gets(tmpbuff);

    /* bind */
    recvaddr.sin_family = AF_INET;
    recvaddr.sin_port = htons(50000);
    recvaddr.sin_addr.s_addr = inet_addr("192.168.3.255");
    nsize = sendto(sockfd, tmpbuff, strlen(tmpbuff), 0, (struct sockaddr *)&recvaddr, 
                   sizeof(recvaddr));
    if (-1 == nsize)
    {
        perror("fail to snedto");
        return -1;
    }

    /* recvfrom */
    memset(tmpbuff, 0, sizeof(tmpbuff));
    nsize = recvfrom(sockfd, tmpbuff, sizeof(tmpbuff), 0, NULL, NULL);
    if (-1 == nsize)
    {
        perror("fail to recvfrom");
        return -1;
    }

    printf("%s\n", tmpbuff);
    
    close(sockfd);

    return 0;
}
