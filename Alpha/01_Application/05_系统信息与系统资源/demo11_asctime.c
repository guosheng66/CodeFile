#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    struct tm local_t;
    char tm_str[128] = {0};
    time_t sec;

    /* 获取时间 */
    time(&sec);
    if (-1 == sec)
    {
        perror("time error");
        return -1;
    }

    localtime_r(&sec, &local_t);
    asctime_r(&local_t, tm_str);
    printf("CST: %s", tm_str);
    
    
    return 0;
}
