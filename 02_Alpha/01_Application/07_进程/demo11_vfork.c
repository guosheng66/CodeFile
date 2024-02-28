#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    pid_t pid = 0;
    int num = 100;

    pid = vfork();
    switch (pid)
    {
        case -1:
            perror("vfork error");
            exit(-1);
        case 0:
            /* 子进程 */
            printf("子进程：num = %d\n", num);
            _exit(0);
        default:
            /* 父进程 */
            printf("父进程：num = %d\n", num + 1);
            exit(0);
    }
    
    return 0;
}
