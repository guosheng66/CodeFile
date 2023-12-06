#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int fd = 0;

    /* 打开文件 */
    fd = open("./test.txt", O_RDONLY);
    if (-1 == fd)
    {
        perror("open error");
        _exit(-1);
    }

    close(fd);
    _exit(0);
    
    return 0;
}
