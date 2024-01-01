#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *ptr = NULL;
    char str[] = "Hello World";

    ptr = strchr(str, 'W');
    if (NULL != ptr)
    {
        printf("char: %c\n", *ptr);
        printf("Offset: %ld\n", ptr - str);
    }
    
    return 0;
}
