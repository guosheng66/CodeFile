#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char str[128] = {0};
    char c;

    scanf("%s", str);
    printf("str: %s\n", str);

    scanf("%c", &c);      //此处scanf使用的是%c个是，而不是%s，对于%c读取时，
                          //空格，换行符，TAB这些都是正常字符
    printf("c: %d\n", c); //换行符'\n'对应的ASCII编码值都等于10
    
    return 0;
}
