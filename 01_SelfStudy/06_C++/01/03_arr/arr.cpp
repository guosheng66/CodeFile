#include "arr.h"

void ARR::addtail(int data)
{
    this->data[tail++] = data;
}

void ARR::show(void)
{
    int i = 0;

    for (i = 0; i < tail; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}