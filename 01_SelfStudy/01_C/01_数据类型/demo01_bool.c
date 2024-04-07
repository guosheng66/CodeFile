#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    _Bool a;
    // bool a;

    a = true;
    a = false;
    a = -1; //任何非0的值都代表真

    if (a)
    {
        printf("true %d\n", a);
    }
    else
    {
        printf("false %d\n", a);
    }
    
    return 0;
}
