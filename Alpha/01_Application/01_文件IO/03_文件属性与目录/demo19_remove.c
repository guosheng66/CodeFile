#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int ret = 0;

    ret = remove("./test.file");
    if (-1 == ret)
    {
        perror("remove error");
        exit(-1);
    }
    
    exit(0);
}
