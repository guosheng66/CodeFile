#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MyStrcat(char *dst, char *src)
{
    char *pDst = NULL;
    char *pSrc = NULL;

    pDst = dst;
    while (*pDst != '\0')
    {
        pDst++;
    }

    pSrc = src;
    while (*pSrc != '\0')
    {
        *pDst = *pSrc;
        pSrc++;
        pDst++;
    }

    pDst = '\0'; //在目标字符串末尾添加空字符'\0'

    return 0;
}

int main(int argc, char const *argv[])
{
    char str1[128]= "hello";
    char str2[] = {"world"};

    strcat(str1, str2);
    printf("strcat: %s\n", str1); 

    strncat(str1, str2, 4);
    printf("strncat: %s\n", str1); 
    MyStrcat(str1, str2);
    printf("MyStrcat: %s\n", str1);
    
    return 0;
}
