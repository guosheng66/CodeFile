/*
 *获取文件inode节点编号以及文件大小，并打印
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

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

    /* 打印文件大小和inode编号 */
    printf("file size: %ld bytes\n" "inode number: %ld\n",
           file_stat.st_size, file_stat.st_ino);

    return 0;   
}