#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/* 父子进程的信息共享测试 */
int main(int argc, char const *argv[])
{
    pid_t pid = 0;

    pid = fork();
    switch (pid)
    {
        case -1:
            perror("fork error");
            exit(-1);
        case 0:
            printf("子进程:%d\n", pid);
            _exit(0);
        default:
            printf("父进程:%d\n", pid);
            exit(0);
    }
    
    return 0;
}
