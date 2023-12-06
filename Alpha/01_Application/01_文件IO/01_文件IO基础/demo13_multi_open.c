#include "head.h"

int main(int argc, char const *argv[])
{
    unsigned char buf1[4] = {0};
    unsigned char buf2[4] = {0};
    int fd1 = 0;
    int fd2 = 0;
    int ret = 0;
    int i = 0;

    /* 创建新文件test.txt并打开 */
    fd1 = open("test.txt", O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (-1 == fd1)
    {
        perror("open error");
        exit(-1);
    }

    /* 再次打开test.txt文件 */
    fd2 = open("test.txt", O_RDWR);
    if (-1 == fd2)
    {
        perror("open error");
        ret = -1;
        goto err1;
    }

    /* buf数据初始化 */
    buf1[0] = 0x11;
    buf1[1] = 0x22;
    buf1[2] = 0x33;
    buf1[3] = 0x44;

    buf2[0] = 0xAA;
    buf2[1] = 0xBB;
    buf2[2] = 0xCC;
    buf2[3] = 0xDD;

    /* 循环写入数据 */
    for (i = 0; i < 8; i++)
    {
        ret = write(fd1, buf1, sizeof(buf1));
        if (-1 == ret)
        {
            perror("write error");
            goto err1;
        }

        ret = write(fd2, buf2, sizeof(buf2));
        if (-1 == ret)
        {
            perror("write error");
            goto err2;
        }
    }

    /* 将读写位置偏移量移动到文件头 */
    ret = lseek(fd1, 0, SEEK_SET);
    if (-1 == ret)
    {
        perror("lseek error");
        goto err2;
    }

    /* 读取数据 */
    for (i = 0; i < 8; i++)
    {
        ret = read(fd1, buf1, sizeof(buf1));
        if (-1 == ret)
        {
            perror("read error");
            goto err2;
        }
    }

    printf("%x %x %x %x\n", buf1[0], buf1[1], buf1[2], buf1[3]);

    ret = 0;

err2:
    close(fd2);

err1:
    close(fd1);
    exit(ret);

    return 0;
}
