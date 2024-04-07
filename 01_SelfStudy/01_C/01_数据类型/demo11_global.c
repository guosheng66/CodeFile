#include <stdio.h>

int global_a = 0;

void Fun()
{
    int i = 0;

    for (i = 0; i < 5; i++)
    {
        static int a;
        a++;

        global_a++;
        printf("a = %d global_a = %d\n", a, global_a);
    }
}

int main(int argc, char const *argv[])
{
    Fun();
    Fun();
    
    return 0;
}
