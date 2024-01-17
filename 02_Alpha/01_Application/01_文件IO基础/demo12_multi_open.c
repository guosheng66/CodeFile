/* 一个进程内多次open打开同一个文件，在内存中并不会存在多份动态文件 */
#include "head.h"

int main(int argc, char const *argv[])
{
    char buf[16] = {0};
    int fd1 = 0;
    int fd2 = 0;
    int ret = 0;

    /* 创建test.txt文件并打开 */
    fd1 = open("test.txt", O_RDWR | O_CREAT |O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (-1 == fd1)
    {
        perror("open error");
        exit(-1);
    }

    /* 再次打开test/txt文件 */
    fd2 = open("test.txt", O_RDWR);
    if (-1 == fd2)
    {
        perror("open error");
        ret = -1;
        goto err1;
    }

    /* 通过fd1文件描述符写入4个字节数据 */
    buf[0] = 0x11;
    buf[1] = 0x22;
    buf[2] = 0x33;
    buf[4] = 0x44;

    ret = write(fd1, buf, 4);
    if (-1 == ret)
    {
        perror("write error");
        goto err2;
    }

    /* 将读写位置偏移到文件头 */
    ret = lseek(fd2, 0, SEEK_SET);
    if (-1 == ret)
    {
        perror("lseek error");
        goto err2;
    }

    /* 读取数据 */
    memset(buf, 0x00, sizeof(buf));
    ret = read(fd2, buf, 4);
    if (-1 == ret)
    {
        perror("read error");
        goto err2;
    }

    printf("0x%x 0x%x 0x%x 0x%x\n", buf[0], buf[1], buf[2], buf[3]);
    ret = 0;

err2:
    close(fd2);

err1:
    close(fd1);
    exit(ret);
    
    return 0;
}

/* 一个进程内多次open打开同一个文件，不同文件描述符所对应的读写位置偏移两是相互独立的 */