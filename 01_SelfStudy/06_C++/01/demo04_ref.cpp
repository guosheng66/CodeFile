#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 100;
    int &b = a;

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    printf("addr: a = %p\n", &a);
    printf("addr: b = %p\n", &b);

    return 0;
}
