#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    pid_t pid = getpid();

    printf("进程组ID: %d -- getpgrp()\n", getpgrp());
    printf("进程组ID: %d -- getpgid()\n", getpgid(0));
    printf("进程组ID: %d -- getpgid(%d)\n", getpgid(pid), pid);
    
    return 0;
}
