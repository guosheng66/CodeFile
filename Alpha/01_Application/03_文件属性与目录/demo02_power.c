/*
 * 获取文件的类型，判断此文件对于其它用户（Other）是否具有可读可写权限。
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
    struct stat file_stat;
    int ret = 0;

    /* 获取文件属性 */
    ret = stat("./test.file", &file_stat);
    if (-1 == ret)
    {
        perror("stat error");
        exit(-1);
    }

    /* 判断文件类型 */
    switch(file_stat.st_mode & __S_IFMT)
    {
        case __S_IFSOCK: printf("socket"); break;
        case __S_IFLNK:  printf("symbolic link"); break;
        case __S_IFREG:  printf("regular file"); break;
        case __S_IFBLK:  printf("block defice"); break;
        case __S_IFDIR:  printf("directory"); break;
        case __S_IFCHR:  printf("character device"); break;
        case _SC_FIFO:   printf("FIFO"); break;
    }

    printf("\n");

    /* 判断其他用户对该文件是否具有读权限 */
    if (file_stat.st_mode & S_IROTH)
    {
        printf("Read: Yes\n");
    }
    else
    {
        printf("Read: No\n");
    }

    /* 判断其他用户对该文件是否具有写权限 */
    if (file_stat.st_mode & S_IWOTH)
    {
        printf("Write: Yes\n");
    }
    else
    {
        printf("Write: No\n");
    }

    exit(0);
}