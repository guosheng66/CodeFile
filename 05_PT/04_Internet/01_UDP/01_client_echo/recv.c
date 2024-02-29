#include "head.h"

int main(int argc, char const *argv[])
{
    int ret = 0;
    int sockfd = 0;
    char tmpbuff[4096] = {0};
    char sendbuff[4096] = {0};
    struct sockaddr_in recvaddr;
    struct sockaddr_in sendaddr;
    socklen_t addrlen = sizeof(sendaddr);
    ssize_t nsize = 0;

    /* 创建套接字 */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (-1 == sockfd)
    {
        perror("fail to sockfd");
        return -1;
    }

    /* 绑定地址信息 */
    recvaddr.sin_family = AF_INET;
    recvaddr.sin_port = htons(50000);
    recvaddr.sin_addr.s_addr = inet_addr("192.168.3.108");
    ret = bind(sockfd, (struct sockaddr *)&recvaddr, sizeof(recvaddr));
    if (-1 == ret)
    {
        perror("fail to bind");
        return -1;
    }

    /* 接收数据 */
    nsize = recvfrom(sockfd, tmpbuff, sizeof(tmpbuff), 0, (struct sockaddr*)&sendaddr, &addrlen);
    if (-1 == nsize)
    {
        perror("fail to recvfrom");
        return -1;
    }

    printf("RECV(from send):%s#%d->%s\n", inet_ntoa(sendaddr.sin_addr), ntohs(sendaddr.sin_port), tmpbuff);

    /* 回复信息 */
    nsize = sendto(sockfd, tmpbuff, strlen(tmpbuff), 0, (struct sockaddr*)&sendaddr, sizeof(sendaddr));
    if (-1 == nsize)
    {
        perror("fail to snedto");
        return -1;
    }

    close(sockfd);
    
    return 0;
}
