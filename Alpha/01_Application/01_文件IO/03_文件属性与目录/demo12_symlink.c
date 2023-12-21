#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int ret = 0;

    ret = symlink("./test.file", "soft2");
    if (-1 == ret)
    {
        perror("sumlink error");
        exit(-1);
    }

    exit(0);
    
    return 0;
}
