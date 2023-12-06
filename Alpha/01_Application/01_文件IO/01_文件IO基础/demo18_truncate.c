#include "head.h"

int main(int argc, char const *argv[])
{
    int fd = 0;

    /* 打开文件 */
    if (0 > (fd = open("test.txt", O_RDWR)))
    {
        perror("oen error");
        exit(-1);
    }

    /* 使用ftruncate将文件截断为长度0字节 */
    if (0 > ftruncate(fd, 0))
    {
        perror("ftruncate error");
        exit(-1);
    }

    /* 使用truncate将文件截断为长度1024字节 */
    if (0 > truncate("test.txt", 1024))
    {
        perror("truncate error");
        exit(-1);
    }

    /* 关闭文件退出程序 */
    close(fd);
    exit(0);
    
    return 0;
}
