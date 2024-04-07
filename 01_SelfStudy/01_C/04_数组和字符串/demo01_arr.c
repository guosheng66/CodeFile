#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[2][3];
    int i = 0;
    int j = 0;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%p ", &a[i][j]);
        }

        putchar('\n');
    }

    printf("%p %ld\n", a, sizeof(a));
    printf("%p %ld\n", a[0], sizeof(a[0]));
    printf("%p %ld\n", a[1], sizeof(a[1]));
    
    return 0;
}
