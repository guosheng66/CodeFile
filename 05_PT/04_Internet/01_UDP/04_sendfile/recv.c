#include "head.h"

int main(int argc, char const *argv[])
{
    int fd = 0;
    int ret = 0;
    int sockfd = 0;
    ssize_t nsize = 0;
    char tmpbuff[4096] = {0};
    struct sockaddr_in recvaddr;

    /* 创建套接字 */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (-1 == sockfd)
    {
        perror("fail to socket");
        return -1;
    }

    /* 绑定IP地址和端口号 */
    recvaddr.sin_family = AF_INET;
    recvaddr.sin_port = htons(50000);
    recvaddr.sin_addr.s_addr = inet_addr("192.168.3.255");
    ret = bind(sockfd, (struct sockaddr *)&recvaddr, sizeof(recvaddr));
    if (-1 == ret)
    {
        perror("fail to bind");
        return -1;
    }

    /* 接收文件名 */
    memset(tmpbuff, 0, sizeof(tmpbuff));
    nsize = recvfrom(sockfd, tmpbuff, sizeof(tmpbuff), 0, NULL, NULL);
    if (-1 == nsize)
    {
        perror("fail to recvfrom");
        return -1;
    }

    /* 打开文件 */
    fd = open(tmpbuff, O_WRONLY | O_TRUNC| O_CREAT, 0664);
    if (-1 == fd)
    {
        perror("fail to open");
        return -1;
    }

    /* 接收数据并写入文件中 */
    while (1)
    {
        memset(tmpbuff, 0, sizeof(tmpbuff));
        nsize = recvfrom(sockfd, tmpbuff, sizeof(tmpbuff), 0, NULL, NULL);
        if (-1 == nsize)
        {
            perror("fail to recvfrom");
            break;
        }

        /* 判断是否断开连接 */
        if (!strcmp(tmpbuff, "./quit"))
        {
            printf("已断开连接\n");
            break;
        }

        write(fd, tmpbuff, nsize);
    }
    
    close(fd);
    close(sockfd);
    
    return 0;
}
