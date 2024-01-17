#include "head.h"

int main(int argc, char const *argv[])
{
    int fd1 = 0;
    int fd2 = 0;
    int ret = 0;

    /* 打开文件test.txt */
    fd1 = open("test.txt", O_RDONLY);
    if (-1 == fd1)
    {
        perror("open error");
        exit(-1);
    }

    /* 使用fcntl函数赋值一个文件描述符 */
    fd2 = fcntl(fd1, F_DUPFD, 99);
    if (-1 == fd2)
    {
        perror("fcntl error");
        ret = -1;
        goto err;
    }

    printf("fd1: %d\nfd2: %d\n", fd1, fd2);

    ret = 0;
    close(fd2);

err:
    close(fd1);
    exit(ret);
    
    return 0;
}
