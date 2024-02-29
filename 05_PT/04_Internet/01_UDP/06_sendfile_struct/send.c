#include "head.h"

int main(int argc, char const *argv[])
{
    ssize_t nsize = 0;
    int sockfd = 0;
    int fd = 0;
    message_t sendmsg;
    struct sockaddr_in recvaddr;
    off_t len;
    off_t cur;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (-1 == sockfd)
    {
        perror("fail to socket");
        return -1;
    }

    recvaddr.sin_family = AF_INET;
    recvaddr.sin_port = htons(50000);
    recvaddr.sin_addr.s_addr = inet_addr("192.168.3.108");
    
    memset(&sendmsg, 0, sizeof(sendmsg));
    gets(sendmsg.text);
    sendmsg.type = MSG_TYPE_FILENAME;
    nsize = sendto(sockfd, &sendmsg, sizeof(sendmsg), 0, (struct sockaddr *)&recvaddr, sizeof(recvaddr));
    if (-1 == nsize)
    {
        perror("fail to sendto");
        return -1;
    }

    fd = open(sendmsg.text, O_RDONLY);
    if (-1 == fd)
    {
        perror("fail to open");
        return -1;
    }

    len = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    while (1)
    {
        memset(&sendmsg, 0, sizeof(sendmsg));
        sendmsg.len = read(fd, sendmsg.text, sizeof(sendmsg.text));
        if (sendmsg.len <= 0)
        {
            break;
        }

        cur = lseek(fd, 0, SEEK_CUR);
        printf("%.2lf\r", (double)cur / (double)len * 100);
        fflush(stdout);

        sendmsg.type = MSG_TYPE_CONTENT;
        nsize = sendto(sockfd, &sendmsg, sizeof(sendmsg), 0, (struct sockaddr*)&recvaddr, sizeof(recvaddr));
        if (-1 == nsize)
        {
            perror("fail to sendto");
            return -1;
        }

        usleep(5000);
    }
    
    sendmsg.type = MSG_TYPE_EXIT;
    nsize = sendto(sockfd, &sendmsg, sizeof(sendmsg), 0, (struct sockaddr *)&recvaddr, sizeof(recvaddr));
    if (-1 == nsize)
    {
        perror("fail to sendto");
        return -1;
    }

    close(fd);
    close(sockfd);

    return 0;
}
