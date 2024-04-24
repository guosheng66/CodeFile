#include "arr.h"

void rev(ARR &arr)
{
    int i = 0;

    for (i = 0; i < arr.tail / 2; i++)
    {
        int tem = arr.data[i];
        arr.data[i] = arr.data[arr.tail - i - 1];
        arr.data[arr.tail-i-1] =tem;
    }
}

int main(int argc, char const *argv[])
{
    ARR arr;

    arr.addtail(1);
    arr.addtail(2);
    arr.addtail(3);
    arr.addtail(4);

    arr.show();
    rev(arr);

    arr.show();
    
    return 0;
}
