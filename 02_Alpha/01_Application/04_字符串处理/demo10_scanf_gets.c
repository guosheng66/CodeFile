#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char str1[128] = {0};
    char str2[128] = {0};
    
    scanf("%s", str1);
    printf("str1: %s\n", str1);

    gets(str2); //gets读取时会将换行符全部读取，但最终会丢弃换行符，不作为字符串的
                //组成部分，以空格代替
    printf("str2: %s\n", str2);
    
    return 0;
}
