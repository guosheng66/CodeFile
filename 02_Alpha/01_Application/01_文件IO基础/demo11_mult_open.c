/* 一个进程多次open打开同一个文件，那么会得到多个不同的文件描述符，
   同理在关闭文件的时候也需要调用close依次关闭各个文件描述符 */
#include "head.h"

int main(int argc, char const *argv[])
{
    int fd1 = 0;
    int fd2 = 0;
    int fd3 = 0;
    int ret = 0;

    /* 第一次打开文件 */
    fd1 = open("./test.txt", O_RDWR);
    if (-1 == fd1)
    {
        perror("open error");
        exit(-1);
    }

    /* 第二次打开文件 */
    fd2 = open("./test.txt", O_RDWR);
    if (-1 == fd2)
    {
        perror("open error");
        ret = -1;
        goto err1;
    }
    
    /* 第三次打开文件 */
    fd3 = open("./test.txt", O_RDWR);
    if (-1 == fd3)
    {
        perror("open error");
        ret = -1;
        goto err2;
    }

    /* 打印三个文件描述符 */
    printf("%d %d %d\n", fd1, fd2, fd3);

err1:
    close(fd2);

err2:
    close(fd3);
    exit(ret);
    
    return 0;
}
