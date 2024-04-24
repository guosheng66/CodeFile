#ifndef __ARR_H__
#define __ARR_H__

typedef struct arr
{
    int data[100];
    int tail;
}ARR;

void init(ARR *arr);
void addtail(ARR *arr, int data);
void show(ARR *arr);

#endif