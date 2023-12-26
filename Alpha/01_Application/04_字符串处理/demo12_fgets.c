#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[128] = {0};

    fgets(str, sizeof(str), stdin); //读取的str字符串本身会添加字符串
    printf("%s", str);
    
    return 0;
}
