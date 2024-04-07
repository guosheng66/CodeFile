#include <stdio.h>

#define W 3.0e-23
#define C 950

int main(int argc, char const *argv[])
{
    float n = 0;
    float total = 0;

    printf("please input:");
    scanf("%f", &n);

    total = n * C / W;
    printf("%e\n", total);
    
    return 0;
}
