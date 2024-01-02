#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char buf[512] = {0};
    int fd = 0;
    int ret = 0;

    /* 打开文件 */
    fd = open("/proc/version", O_RDONLY);
    if (-1 == fd)
    {
        perror("open error");
        return -1;
    }

    /* 读取文件 */
    ret = read(fd, buf, sizeof(buf));
    if (-1 == ret)
    {
        perror("read() error");
        return -1;
    }

    printf("%s", buf); //打印信息

    close(fd);
    
    return 0;
}
