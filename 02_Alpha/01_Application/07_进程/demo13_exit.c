#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("Hello World\n");
    
    switch (fork())
    {
        case -1:
            perror("fork error");
            exit(-1);
        case 0:
            /* 子进程 */
            _exit(0);
        default:
            /* 父进程 */
            exit(0);
    }

    return 0;
}
