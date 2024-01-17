#include "head.h"

int main(int argc, char const *argv[])
{
    int fd1 = 0;
    int fd2 = 0;
    int ret = 0;

    fd1 = open("test.txt", O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (-1 == fd1)
    {
        perror("open error");
        exit(-1);
    }

    /* 赋值文件描述符 */
    fd2 = dup2(fd2, 100);
    if (-1 == fd2)
    {
        perror("dup error");
        ret = -1;
        goto err;
    }

    printf("fd1: %d\nfd2: %d\n", fd1, fd2);

    close(fd2);

err:
    close(fd1);
    exit(ret);

    return 0;
}
