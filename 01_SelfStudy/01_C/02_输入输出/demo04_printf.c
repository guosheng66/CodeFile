#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 243;
    float f1 = 345.668;
    char ch = 'a';

    printf("%8d\n%2d\n", a, a);
    printf("%9f - %9.2f - %.3f\n", f1, f1, f1);
    printf("ch = %5c\n", ch);
    
    return 0;
}
