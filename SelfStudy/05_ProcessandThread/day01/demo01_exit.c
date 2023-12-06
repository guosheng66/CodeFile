#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("hello world\n");
    _exit(0);
    printf("after exit");
    
    return 0;
}
