#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = 0;

    /* 打开文件 */
    fd = open("./test.txt", O_RDONLY);
    if (-1 == fd)
    {
        perror("open error");
        return -1;
    }

    return 0;
}