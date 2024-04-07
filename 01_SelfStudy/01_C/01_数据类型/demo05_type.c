#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    int a = 2;
    int b = 3;
    int sum = 0;
    float c = 3.14;

    sum = (int)(a + b + c);
    printf("sum = %d\n", sum);
    
    return 0;
}
