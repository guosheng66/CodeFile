#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int ret = 0;

    ret = unlink("./test.file");
    if (-1 == ret)
    {
        perror("unlink error");
        exit(-1);
    }
    
    exit(0);
}
