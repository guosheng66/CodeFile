#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char buf[48] = {0};
    int ret = 0;

    memset(buf, 0, sizeof(buf));
    ret = readlink("./soft2", buf, sizeof(buf));
    if (-1 == ret)
    {
        perror("readlink error");
        exit(-1);
    }

    printf("%s\n", buf);
    exit(0);
    
    return 0;
}
