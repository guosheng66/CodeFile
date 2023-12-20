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
    
    return 0;
}
//page 173 utimr