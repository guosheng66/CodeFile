#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    char tm_str[128] = {0};
    time_t tm;

    /* 获取时间 */
    tm = time(NULL);
    if (-1 == tm)
    {
        perror("time() error");
        return -1;
    }

    /* 将时间转换为字符串形式 */
    ctime_r(&tm, tm_str);
    
    printf("当前时间：%s", tm_str);
    
    return 0;
}
