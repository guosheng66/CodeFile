#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    struct stat file_stat;
    int fd = 0;
    int ret = 0;
    
    /* 打开文件 */
    fd = open("test.file", O_RDONLY);
    if (-1 == fd)
    {
        perror("open error");
        return -1;
    }

    /* 获取文件属性 */
    ret = fstat(fd, &file_stat);
    if (-1 == ret)
    {
        perror("fstat error");
        return -1;
    }

    close(fd);

    return 0;
}
