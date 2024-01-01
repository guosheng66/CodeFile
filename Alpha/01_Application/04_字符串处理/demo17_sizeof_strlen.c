#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str[48] = {"Strlen and sizoef test"};
    char *ptr = str;

    printf("sizeof: %ld\n", sizeof(str));
    printf("strlen: %ld\n", strlen(str));
    puts("------------");
    printf("sizeof: %ld\n", sizeof(ptr)); //这里计算的是指针变量ptr的大小
    printf("strlen: %ld\n", strlen(ptr));

    return 0;
}
