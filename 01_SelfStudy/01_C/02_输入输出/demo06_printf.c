#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 254;
    float f = 23.511;
    char ch = 'a';

    printf("%08d\n%0+8d\n", a, a);
    printf("%09f = %09.2f - %.3f\n", f, f, f);
    printf("ch = %5c\n", ch);
    
    return 0;
}
