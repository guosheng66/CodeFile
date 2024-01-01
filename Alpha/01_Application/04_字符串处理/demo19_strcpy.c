#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MyStrcpy(char *dest, char *src)
{
    char *pDest = NULL;
    char *pSrc = NULL;

    pDest = dest;
    pSrc = src;

    while (*pSrc != '\0')
    {
        *pDest = *pSrc;
        pSrc++;
        pDest++;
    }

    *pDest = '\0';

    return 0;
}

int main(int argc, char const *argv[])
{
    char src[128] = {"hello world"};
    char dest[128] = {0};

    strcpy(dest, src);
    printf("strcpy: %s\n", dest);

    MyStrcpy(dest, src);
    printf("MyStrcpy: %s\n", dest);
    
    return 0;
}
