/* 这个示例很重要，写时间的时候可以用 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    struct tm local_t;
    char tm_str[128] = {0};
    time_t sec;

    /* 获取时间 */
    sec = time(NULL);
    if (-1 == sec)
    {
        perror("time error");
        exit(-1);
    }

    localtime_r(&sec, &local_t);
    strftime(tm_str, sizeof(tm_str), "%Y-%m-%d %A %H:%M:%S", &local_t);
    printf("CST: %s\n", tm_str);

    return 0;
}

