#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <utime.h>
#include <sys/types.h>

#define MY_FILE "test.file"

int main(int argc, char const *argv[])
{
    struct utimbuf utm_buf;
    time_t cur_sec;
    int ret = 0;

    /* 检查文件是否存在 */
    ret = access(MY_FILE, F_OK);
    if (-1 == ret)
    {
        printf("Error: %s file does not exist!\n", MY_FILE);
        exit(-1);
    }

    /* 获取当前时间 */
    time(&cur_sec);
    utm_buf.actime = cur_sec;
    utm_buf.modtime = cur_sec;

    /* 修改文件时间戳 */
    ret = utime(MY_FILE, &utm_buf);
    if (-1 == ret)
    {
        perror("utime error");
        exit(-1);
    }
    
    return 0;
}
