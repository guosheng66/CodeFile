#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    struct tm local_t;
    struct tm utc_t;
    time_t sec;

    /* 获取时间 */
    sec = time(NULL);
    if (-1 == sec)
    {
        perror("time() error");
        exit(-1);
    }

    localtime_r(&sec, &local_t); //转换得到本地时间
    gmtime_r(&sec, &utc_t);      //转换得到国际标准时间

    /* 打印输出 */
    printf("%d年 %02d月 %02d日 %02d:%02d:%02d CST\n", local_t.tm_year + 1900,
           local_t.tm_mon + 1, local_t.tm_mday, local_t.tm_hour,
           local_t.tm_min, local_t.tm_sec);
    
    printf("%d年 %02d月 %02d日 %02d:%02d:%02d UTC\n", utc_t.tm_year + 1900,
          utc_t.tm_mon + 1, utc_t.tm_mday, utc_t.tm_hour, utc_t.tm_min,
          utc_t.tm_sec);

    
    
    return 0;
}
