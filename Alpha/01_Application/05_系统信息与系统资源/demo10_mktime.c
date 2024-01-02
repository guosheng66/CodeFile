#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    struct tm local_t;
    time_t sec;

    /* 获取时间 */
    sec = time(NULL);
    if (-1 == sec)
    {
        perror("time() error");
        return -1;
    }

    printf("获得的秒数：%ld\n", sec);
    localtime_r(&sec, &local_t); 
    printf("转换得到的秒数：%ld\n", mktime(&local_t));   
    
    return 0;
}
