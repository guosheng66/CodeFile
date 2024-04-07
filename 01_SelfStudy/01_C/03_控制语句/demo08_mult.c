#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    int j = 0;

    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d * %d = %-5d", j, i, j * i);
        }

        printf("\n");
    }
    
    return 0;
}
