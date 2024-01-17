#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *ptr = NULL;
    char str[] = "hello hello";

    ptr = strchr(str, 'o');
    if (NULL != ptr)
    {
        printf("strchr: %ld\n", ptr - str);
    }

    ptr = strrchr(str, 'o');
    if (NULL != ptr)
    {
        printf("strrchr: %ld\n", ptr - str);
    }
    
    return 0;
}
