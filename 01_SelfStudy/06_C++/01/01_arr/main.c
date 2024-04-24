#include <stdio.h>
#include "arr.h"

int main(int argc, char const *argv[])
{
    int n = 10;
    ARR arr;
    
    init(&arr);
    
    while (n--)
    {
        addtail(&arr, n);
    }
    show(&arr);

    ARR arr1;
    
    init(&arr1);

    int i = 0;

    for (i = 0; i < 10; i++)
    {
        addtail(&arr1, i);
    }

    show(&arr1);
 
    return 0;
}

