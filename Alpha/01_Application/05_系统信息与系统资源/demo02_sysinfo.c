#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

int main(int argc, char const *argv[])
{
    struct sysinfo sys_info;
    int ret = 0;
    
    ret = sysinfo(&sys_info);
    if (-1 == ret)
    {
        perror("sysinfo() error");
        exit(-1);
    }

    /* 打印信息 */
    printf("uptime: %ld\n", sys_info.uptime);
    printf("totalram: %ld\n", sys_info.totalram);
    
    return 0;
}
