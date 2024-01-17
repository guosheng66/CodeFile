#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[5][4] = {0};
    int (*p)[4] = a;

    printf("%d\n", *(*(p + 2) + 3)); //等价于a[2][3]
    
    return 0;
}
