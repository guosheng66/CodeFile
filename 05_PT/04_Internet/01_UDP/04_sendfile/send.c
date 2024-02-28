#include "head.h"

int main(int argc, char const *argv[])
{
    ssize_t nsize = 0;
    int sockfd = 0;
    int fd = 0;
    char tmpbuff[4096] = {0};
    struct sockaddr_in recvaddr;
    int on = 1;

    /* 创建套接字 */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (-1 == sockfd)
    {
        perror("fail to socket");
        return -1;
    }

    setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR | SO_BROADCAST,&on,sizeof(on));

    /* 绑定IP信息 */
    recvaddr.sin_family = AF_INET;
    recvaddr.sin_port = htons(50000);
    recvaddr.sin_addr.s_addr = inet_addr("192.168.3.255");
    
    /* 发送文件名 */
    printf("请输入要发送的文件名称：");
    gets(tmpbuff); //获取文件名称
    nsize = sendto(sockfd, tmpbuff, strlen(tmpbuff), 0, (struct sockaddr *)&recvaddr, 
                   sizeof(recvaddr));
    if (-1 == nsize)
    {
        perror("fail to sendto");
    }
    
    /* 打开文件 */
    fd = open(tmpbuff, O_RDONLY);
    if (-1 == fd)
    {
        perror("fail to open");
        return -1;
    }
    
    /* 发送文件内容 */
    while (1)
    {
        memset(tmpbuff, 0, sizeof(tmpbuff));
        nsize = read(fd, tmpbuff, sizeof(tmpbuff));
        
        /* 文件末尾停止读取 */
        if (nsize <= 0)
        {
            break;
        }

        nsize = sendto(sockfd, tmpbuff, nsize, 0, (struct sockaddr *)&recvaddr,
                       sizeof(recvaddr));
        if (-1 == nsize)
        {
            perror("fail to sento");
            return -1;
        }

        usleep(20000);
    }

    close(fd); //关闭文件描述符
    
    /* 发送退出标志 */
    memset(tmpbuff, 0, sizeof(tmpbuff));
    sprintf(tmpbuff, "./quit");
    nsize = sendto(sockfd, tmpbuff, strlen(tmpbuff), 0, (struct sockaddr *)&recvaddr,
                  sizeof(recvaddr));
    if (-1 == nsize)
    {
        perror("fail to sendto");
        return -1;
    }
    printf("已断开连接\n");

    close(sockfd);

    return 0;
}
