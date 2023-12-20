#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MY_FILE "./test.file"

int main(int argc, char const *argv[])
{
    struct timeval tmval_arr[2];
    time_t cur_sec;
    int ret = 0;
    int i = 0;

    /* 检查文件是否存在 */
    ret = access(MY_FILE, F_OK);
    if (-1 == ret)
    {
        printf("Error: %s file does not exist!\n", MY_FILE);
        exit(-1);
    }

    /* 获取当前时间 */
    time(&cur_sec);
    for (i = 0; i < 2; i++)
    {
        tmval_arr[i].tv_sec = cur_sec;
        tmval_arr[i].tv_usec = 0;
    }

    /* 修改文件时间戳 */
    ret = utimes(MY_FILE, tmval_arr);
    if (-1 == ret)
    {
        perror("utimes error");
        exit(-1);
    }

    return 0;
}
