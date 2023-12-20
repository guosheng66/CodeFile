#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (-1 == chown("test.file", 0, 0))
    {
        perror("chown error");
        exit(-1);
    }
    
    exit(0);
}
