#include <stdio.h>
#include <string.h>

int MyStrlen(char *str)
{
    char *pStr = NULL;
    int cnt = 0;

    pStr = str;

    while (*pStr != '\0')
    {
        cnt++;
        *pStr++;
    }
    
    return cnt;
}

int main(int argc, char const *argv[])
{
    char str[] = "hello world";

    printf("string: %s\n", str);
    printf("strlen: %ld\n", strlen(str));
    printf("MyStrlen: %d\n", MyStrlen(str));
    
    return 0;
}
