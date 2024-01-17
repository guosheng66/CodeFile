#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("每个用户的最大并发进程数：%ld\n", sysconf(_SC_CHILD_MAX));
    printf("系统节拍率：%ld\n", sysconf(_SC_CLK_TCK));
    printf("系统页大小：%ld\n", sysconf(_SC_PAGE_SIZE));
    
    return 0;
}
