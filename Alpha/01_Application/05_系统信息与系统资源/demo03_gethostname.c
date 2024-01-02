#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char hostname[24] = {0};
    int ret = 0;

    memset(hostname, 0, sizeof(hostname));
    ret = gethostname(hostname, sizeof(hostname));
    if (-1 == ret)
    {
        perror("gethostname error");
        exit(ret);
    }
    
    puts(hostname);

    return 0;
}
