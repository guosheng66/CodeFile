#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd = 0;

    /* 打开文件 */
    fd = open("./test.txt", O_WRONLY | O_TRUNC);
    if (-1 == fd)
    {
        perror("open error");
        exit(-1);
    }

    close(fd);

    exit(0);
}