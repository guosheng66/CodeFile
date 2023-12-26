/* 使用fcntl函数设置文件状态 */
#include "head.h"

int main(int argc, char const *argv[])
{
    int fd = 0;
    int ret = 0;
    int flag = 0;

    /* 打开文件test.txt */
    fd = open("test.txt", O_RDWR);
    if (-1 == fd)
    {
        perror("open error");
        exit(-1);
    }

    /* 获取文件状态标志 */
    flag = fcntl(fd, F_GETFL);
    if (-1 == flag)
    {
        perror("fcntl F_GETFL error");
        ret = -1;
        goto err;
    }

    printf("flag: 0x%x\n", flag);

    /* 设置文件状态标志，添加_APPEND标志 */
    ret = fcntl(fd, F_SETFL, flag | O_APPEND);
    if (-1 == ret)
    {
        perror("fcntl F_SETFL error");
        goto err;
    }

    ret = 0;

err:
    close(fd);
    exit(ret);
    
    return 0;
}
