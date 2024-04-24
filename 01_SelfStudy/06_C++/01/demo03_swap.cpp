#include <stdio.h>

#if 0
int swap(int a, int b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

void swap(int *p, int *q)
{
    *p ^= *q;
    *q ^= *p;
    *p ^= *q;
}
#endif

void swap(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

int main(int argc, char const *argv[])
{
    int a = 100;
    int b = 10;

    swap(a, b);
    printf("a = %d, b = %d\n", a, b);
    
    return 0;
}
