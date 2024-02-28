#include "head.h"

int main(int argc, char const *argv[])
{
    int sockfd = 0;
    char tmpbuff[4096] = {"hello world"};
    struct sockaddr_in recvaddr;
    ssize_t nsize = 0;
    int on = 1;

    /* 创建套接字 */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (-1 == sockfd)
    {
        perror("fail to socket");
        return -1;        
    }
    
    setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR | SO_BROADCAST,&on,sizeof(on)); //权限设置

    recvaddr.sin_family = AF_INET;
    recvaddr.sin_port = htons(50000);
    recvaddr.sin_addr.s_addr = inet_addr("192.168.3.255");

    /* 向对方发送内容 */
    nsize = sendto(sockfd, tmpbuff, strlen(tmpbuff), 0, (struct sockaddr*)&recvaddr, sizeof(recvaddr));
    if (-1 == nsize)
    {
        perror("fail to snedto");
        return -1;
    }

    /* 接收对方回复的消息 */
    memset(tmpbuff, 0, sizeof(tmpbuff));
    nsize = recvfrom(sockfd, tmpbuff, sizeof(tmpbuff), 0, NULL, NULL);
    if (-1 == nsize)
    {
        perror("fail to recvfrom");
        return -1;
    }

    printf("RECV(from recv):%s\n", tmpbuff);

    close(sockfd); //关闭套接字
    
    return 0;
}
