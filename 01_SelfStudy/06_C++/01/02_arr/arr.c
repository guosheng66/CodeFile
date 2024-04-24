#include "arr.h"

static void addtail(ARR *arr, int data)
{
    arr->data[arr->tail++] = data;
}

static void show(ARR *arr)
{
    int i = 0;

    for (i = 0; i < arr->tail; i++)
    {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

void init(ARR *arr)
{
    arr->tail = 0;
    
    arr->addtail = addtail;
    arr->show = show;
}