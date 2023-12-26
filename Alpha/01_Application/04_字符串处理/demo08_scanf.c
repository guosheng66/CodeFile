#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char str1[128] = {0};
    char str2[128] = {0};

    scanf("%s", str1);
    printf("str1: %s\n", str1);

    scanf("%s", str2);
    printf("str2: %s\n", str2);
    
    return 0;
}
