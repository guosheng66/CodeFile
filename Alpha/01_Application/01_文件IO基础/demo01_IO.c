#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    char buff[1024] = {0};
    int fd1 = 0;
    int fd2 = 0;
    int ret = 0;

    /* 打开源文件src.txt(只读方式) */
    fd1 = open("src.txt", O_RDONLY);
    if (-1 == fd1)
    {
        perror("fail to open");
        return fd1;
    }

    /* 打开目标文件dest.txt(只写方式) */
    fd2 = open("dest.txt", O_WRONLY);
    if (-1 == fd2)
    {
        perror("fdil to open");
        ret = fd2;

        goto out2;
    }

    /* 读取源文件1KB数据到buff中 */
    ret = read(fd1, buff, sizeof(buff));
    if (-1 == ret)
    {
        perror("fail to read");
        goto out1;
    }

    /* 将buffer中的数据写入目标文件 */
    ret = write(fd2, buff, sizeof(buff));
    if (-1 == ret)
    {
        perror("fail to write");
        goto out2;
    }


    ret = 0;

out1:
    close(fd1); //关闭目标文件
    return ret;

out2:
    close(fd2); //关闭目标文件
    return ret;

    return ret;
}