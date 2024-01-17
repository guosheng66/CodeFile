#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    int ret = 0;

    ret = mkdir("./dir01", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
    if (-1 == ret)
    {
        perror("mkdir error");
        exit(-1);
    }
    
    return 0;
}
