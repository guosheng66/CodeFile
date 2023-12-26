#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <utime.h>

#define MY_FILE "./test.file"

int main(int argc, char const *argv[])
{
    struct timespec tmsp_arr[2];
    int ret = 0;
    int fd = 0;

    /* 检查文件是否存在 */
    ret = access(MY_FILE, F_OK);
    if (-1 == ret)
    {
        perror("access error");
        exit(-1);
    }

    /* 打开文件 */
    fd = open(MY_FILE, O_RDONLY);
    if (-1 == fd)
    {
        perror("open error");
        exit(-1);
    }

    /* 修改文件时间戳 */
    ret = futimens(fd, NULL); //设置为当前时间

    close(fd);
    exit(ret);
    
    return 0;
}
//下面为源程序，但源程序在修改时间戳的时候出现未定义宏编译错误
#if 0
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define MY_FILE "./test_file"
int main(void)
{
 struct timespec tmsp_arr[2];
 int ret;
 int fd;
 /* 检查文件是否存在 */
 ret = access(MY_FILE, F_OK);
 if (-1 == ret) {
 printf("Error: %s file does not exist!\n", MY_FILE);
 exit(-1);
 }
 /* 打开文件 */
 fd = open(MY_FILE, O_RDONLY);
 if (-1 == fd) {
 perror("open error");
 exit(-1);
 }
 /* 修改文件时间戳 */
#if 1
 ret = futimens(fd, NULL); //同时设置为当前时间
#endif
#if 0
 tmsp_arr[0].tv_nsec = UTIME_OMIT;//访问时间保持不变
 tmsp_arr[1].tv_nsec = UTIME_NOW;//内容修改时间设置为当期时间
 ret = futimens(fd, tmsp_arr);
#endif
#if 0
 tmsp_arr[0].tv_nsec = UTIME_NOW;//访问时间设置为当前时间
 tmsp_arr[1].tv_nsec = UTIME_OMIT;//内容修改时间保持不变
 ret = futimens(fd, tmsp_arr);
#endif
 if (-1 == ret) {
 perror("futimens error");
 goto err;
 }
err:
 close(fd);
 exit(ret);
}
#endif