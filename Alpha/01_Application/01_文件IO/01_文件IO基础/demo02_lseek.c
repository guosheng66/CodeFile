#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd = 0;
    off_t off = 0; 

    /* 将读写位置移动到文件开头处 */
    off = lseek(fd, 0, SEEK_SET);
    if (-1 == off)
    {
        perror("fail to lseek");
        return -1;
    }

    /* 将读写位置移动到文件末尾 */
    off = lseek(fd, 0, SEEK_END);
    if (-1 == off)
    {
        perror("fail to lseek");
        return -1;   
    }

    /* 将读写位置移动到偏移文件开头100个字节处 */
    off = lseek(fd, 100, SEEK_SET);
    if (-1 == off)
    {
        perror("fail to lseek");
        return -1;
    }

    /* 获取当前读写位置偏移量 */
    off = lseek(fd, 0, SEEK_CUR);
    if (-1 == off)
    {
        perror("fail to lseek");
        return -1;
    }    

    return 0;
}
