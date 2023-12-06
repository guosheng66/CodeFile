#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int fd = 0;
    int ret = 0;
    int i = 0;
    char buffer[1024] = {0};

    /* 打开文件 */
    fd = open("./hole.txt", O_WRONLY | O_CREAT | O_EXCL, S_IRUSR |S_IWUSR | S_IRGRP | S_IROTH);
    if (-1 == fd)
    {
        perror("open error");
        exit(-1);
    }

    /* 将文件读写位置移动到偏移文件头4096个字节（4K）处 */
    ret = lseek(fd, 4096, SEEK_SET);
    if (-1 == ret)
    {
        perror("lseek error");
        goto err;
    }

    /* 初始化buffer为0xFF */
    memset(buffer, 0xFF, sizeof(buffer));

    /* 循环写入4次，每次写入1K */
    for (i = 0; i < 4; i++)
    {
        ret = write(fd, buffer, sizeof(buffer));
        if (-1 == ret)
        {
            perror("write error");
            goto err;
        }
    }

    ret = 0;

err:
    close(fd);

    exit(ret);

    return 0;
}
/* 空洞文件，大小为8K，实际占用4K空间，偏移的4K内存直到正式写入的时候才会申请实际空间 */