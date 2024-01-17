#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

int main(int argc, char const *argv[])
{
    struct utsname os_info;
    int ret = 0;

    /* 获取信息 */
    ret = uname(&os_info);
    if (-1 == ret)
    {
        perror("uname() error");
        return -1;
    }

    /* 打印信息 */
    printf("操作系统名称： %s\n", os_info.sysname);
    printf("主机名：%s\n", os_info.nodename);
    printf("内核版本：%s\n", os_info.release);
    printf("发行版本：%s\n", os_info.release);
    printf("硬件架构：%s\n", os_info.machine);
    
    return 0;
}
