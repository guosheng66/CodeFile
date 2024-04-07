#include <stdio.h>

void Fun()
{
    auto int a = 1, i;

    for (i = 0; i < 5; i++)
    {
        a++;
        printf("a = %d\n", a);
    }
}

int main(int argc, char const *argv[])
{
    int i = 0;
    int a = 100;

    Fun();
    
    for (i = 0; i < 5; i++)
    {
        auto int a = 1;
        a++;

        printf("a = %d\n", a);
    }

    printf("a = %d\n", a);

    return 0;
}
