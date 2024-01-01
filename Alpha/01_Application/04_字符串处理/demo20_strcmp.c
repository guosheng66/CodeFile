#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Mystrcmp(char *str1, char *str2)
{
    char *pStr1 = NULL;
    char *pStr2 = NULL;
    
    pStr1 = str1;
    pStr2 = str2;

    while (*pStr1 != '\0' && *pStr2  != '\0')
    {
        if (*pStr1 != *pStr2)
        {
            return (*pStr1 - *pStr2);
        }

        /* 继续比较后续字符 */
        pStr1++;
        pStr2++;
    }

    /* 当其中一个字符串结束时，检查另一个字符串的结束情况 */
    if (*pStr1 == '\0' && *pStr2 == '\0')
    {
        return 0;
    }
    else if (*pStr1 == '\0')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int main(int argc, char const *argv[])
{
    char str1[128] = {"ABCDABCD"};
    char str2[128] = {"ABCDBBCD"};

    printf("strcmp: %d\n", strcmp(str1, str2));
    printf("strncmp: %d\n", strncmp(str1, str2, 4));
    printf("MyStrcmp: %d\n",Mystrcmp(str1, str2));
    
    return 0;
}
