#include <stdio.h>

int main(int argc, char const *argv[])
{
    int year = 2000;
    int n = 0;

    while (year <= 2500)
    {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        {
            printf("%d is leap\n", year);
            n++;
        }

        year++;
    }

    printf("n = %d\n", n);
    
    return 0;
}
