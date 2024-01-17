#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char const *argv[])
{
    struct timeval tval;
    int ret = 0;

    ret = gettimeofday(&tval, NULL);
    if (-1 == ret)
    {
        perror("gettimeofday error");
        return -1;
    }

    printf("时间值：%ld秒 + %ld微秒\n", tval.tv_sec, tval.tv_usec);
    
    return 0;
}
