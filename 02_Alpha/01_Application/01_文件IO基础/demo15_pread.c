#include "head.h"

int main(int argc, char const *argv[])
{
    unsigned char buf[128] = {0};
    int fd = 0;
    int ret = 0;

    /* 打开文件test.txt */
    fd = open("test.txt", O_RDWR);
    if (-1 == fd)
    {
        perror("open error");
        exit(-1);
    }

    /* 使用pthread函数读取数据（从偏移文件头1024字节处开始读取） */
    ret = pread(fd, buf, sizeof(buf), 1024);
    if (-1 == ret)
    {
        perror("pread error");
        goto err;
    }

    /* 获取当前位置偏移量 */    
    ret = lseek(fd, 0, SEEK_CUR);
    if (-1 == ret) 
    {
        perror("lseek error");
        goto err;
    }

    printf("Current Offset: %d\n", ret);
    ret = 0;

err:
    close(fd);
    exit(ret);
    
    return 0;
}
