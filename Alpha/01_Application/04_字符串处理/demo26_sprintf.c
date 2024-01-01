/* 数字转字符串 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char str[24] = {0};

    sprintf(str, "%d", 500);
    puts(str);

    memset(str, 0, sizeof(str));
    sprintf(str, "%f", 500.111);
    puts(str);

    memset(str, 0, sizeof(str)); 
    sprintf(str, "%u", 500);
    puts(str);
    
    return 0;
}
