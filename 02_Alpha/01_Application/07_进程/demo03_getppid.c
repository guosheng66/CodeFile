#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    pid_t pid = 0;
    pid_t ppid = 0;

    pid = getpid();
    printf("该进程的ID号是：%d\n", pid);

    ppid = getppid();
    printf("该进程的父进程ID号是：%d\n", ppid);
    
    return 0;
}
