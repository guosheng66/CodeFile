#ifndef __ARR_H__
#define __ARR_H__

#include <stdio.h>

typedef struct arr
{
    int data[100];
    int tail;

    void (*addtail)(struct arr *arr, int data);
    void (*show)(struct arr *arr);
}ARR;

void init(struct arr *arr);

#endif