#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    pid_t pid = 0;

    pid = fork();

    switch (pid)
    {
        case -1:
            perror("fork error");
            return -1;
        case 0:
            printf("子进程：pid:%d, ppid:%d\n", getpid(), getppid());
            _exit(0); //子进程使用_exit退出
        default:
            printf("父进程：pid:%d, ppid:%d\n", getpid(), getppid());
            _exit(0); //子进程使用_exit退出
    }
    
    return 0;
}
