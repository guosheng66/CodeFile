#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char buf[16] = {0};
    int fd = 0;
    int ret = 0;

    /* 打开文件 */
    fd = open("./test.txt", O_RDWR | O_APPEND);
    if (-1 == fd)
    {
        perror("fail to open");
        exit(-1);
    }

    /* 初始化buf中的数据 */
    memset(buf, 0x55, sizeof(buf));

    /* 向test.txt中写入4个字节数据 */
    ret = write(fd, buf, 4);
    if (-1 == ret)
    {
        perror("write error");
        goto err;
    }

    /* 将buffer缓冲区中的数据全部清0 */
    memset(buf, 0x00, sizeof(buf));

    /* 将位置偏移量移动到距离文件末尾4个字节处 */
    ret = lseek(fd, -4, SEEK_END);
    if (-1 == ret)
    {
        perror("fail to lseek");
        goto err;
    }

    /* 读取数据 */
    ret = read(fd, buf, 4);
    if (-1 == ret)
    {
        perror("read error");
        goto err;
    }

    printf("0x%x 0x%x 0x%x 0x%x\n", buf[0], buf[1], buf[2], buf[3]);

    ret = 0;

err:
    /* 关闭文件 */
    close(fd);
    exit(ret);

    return 0;
}
