#include <stdio.h>
#include "arr.h"

void init(ARR *arr)
{
    arr->tail = 0;
}

void addtail(ARR *arr, int data)
{
    arr->data[arr->tail++] = data;
}

void show(ARR *arr)
{
    int i = 0;

    for (; i < arr->tail; i++)
    {
        printf("%d ", arr->data[i]);
    }

    printf("\n");
}