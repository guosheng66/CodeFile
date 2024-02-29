#include "head.h"

int main(int argc, char const *argv[])
{
    int ret = 0;
    int sockfd = 0;
    struct sockaddr_in recvaddr;
    message_t recvmsg;
    ssize_t nsize = 0;
    int fd = 0;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (-1 == sockfd)
    {
        perror("fail to scoket");
        return -1;
    }

    recvaddr.sin_family = AF_INET;
    recvaddr.sin_port = htons(50000);
    recvaddr.sin_addr.s_addr = inet_addr("192.168.3.108");
    ret = bind(sockfd, (struct sockaddr *)&recvaddr, sizeof(recvaddr));
    if (-1 == ret)
    {
        perror("fail to bind");
        return -1;
    }

    while (1)
    {
        nsize = recvfrom(sockfd, &recvmsg, sizeof(recvmsg), 0, NULL, NULL);
        if (-1 == nsize)
        {
            perror("fail to recvfrom");
            return -1;
        }

        if (recvmsg.type == MSG_TYPE_FILENAME)
        {
            fd = open(recvmsg.text, O_WRONLY | O_CREAT | O_TRUNC, 0664);
            if (-1 == fd)
            {
                perror("fail to open");
                return -1;
            }
        }
        else if (recvmsg.type == MSG_TYPE_CONTENT)
        {
            write(fd , recvmsg.text, recvmsg.len);
        }
        else if (recvmsg.type == MSG_TYPE_EXIT)
        {
            close(fd);
            close(sockfd);
            break;
        }        
    }
    
    return 0;
}
