#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *ptr =  NULL;
    char *str = "Hello World";

    ptr = strstr(str, "World");
    if (NULL != ptr)
    {
        printf("String: %s\n", str);
        printf("Offset: %ld\n", ptr - str);
    }
    
    return 0;
}
