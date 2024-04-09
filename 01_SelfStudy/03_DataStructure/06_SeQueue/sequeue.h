#ifndef __SEQUEUE_H__
#define __SEQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 128

typedef int datatype;

typedef struct
{
    datatype data[MAXLEN];
    int front;
    int rear;
}sequeue;

extern sequeue *CreateQueue();
extern int EnQueue(sequeue *sq, datatype x);
extern datatype DeQueue(sequeue *sq);
extern int EmptyQueue(sequeue *sq);
extern int FullQueue(sequeue *sq);
extern sequeue *FreeQueue(sequeue *sq);

#endif
