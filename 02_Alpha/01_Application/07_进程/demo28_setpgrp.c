#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    printf("更改前进程组ID: %d\n", getpgrp());
    setpgrp();
    printf("更改后进程组ID: %d\n", getpgrp());
    
    return 0;
}