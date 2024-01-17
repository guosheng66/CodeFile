#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    struct tm t;
    time_t sec;
    
    /* 获取时间 */
    sec = time(NULL);
    if (-1 == sec)
    {
        perror("time error");
        return -1;
    }

    /* 转换获得本地时间 */
    localtime_r(&sec, &t);

    /* 打印输出 */
    printf("%d年 %02d月 %02d日 %d:%d:%d CST\n", t.tm_year + 1900, 
          t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);
    
    return 0;
}
