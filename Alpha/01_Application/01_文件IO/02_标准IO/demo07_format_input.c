#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int a = 0;
    float b = 0;
    char *str = NULL; //定义指向字符的指针

    printf("请输入一个整数:\n");
    scanf("%d", &a);
    printf("输入的整数：%d\n", a);

    printf("请输入一个浮点数：\n");
    scanf("%f", &b);
    printf("输入的浮点数：%f\n", b);

    printf("请输入一个字符串\n");
    scanf("%ms", &str);
    printf("输入的字符串%s\n", str);

    free(str); //字符串会占用内存
    
    return 0;
}
