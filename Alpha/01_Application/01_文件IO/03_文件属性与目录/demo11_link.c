#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int ret = 0;

    ret = link("./test.file", "./hard3");
    if (-1 == ret)
    {
        perror("link error");
        exit(-1);
    }

    exit(0);
    
    return 0;
}
