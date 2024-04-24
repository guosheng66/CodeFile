#include "arr.h"

int main(int argc, char const *argv[])
{
    ARR arr;

    init(&arr);

    int n = 10;
    while (n--)
    {
        arr.addtail(&arr, n);
    }

    arr.show(&arr);

    // arr.show(&arr);
    
    return 0;
}
