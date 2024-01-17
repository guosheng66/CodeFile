#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char str[128] = {0};
    char *ptr = NULL;

    ptr = gets(str);
    if (NULL == ptr)
    {
        perror("gets() error");
        return -1;
    }

    puts(str);
    
    return 0;
}