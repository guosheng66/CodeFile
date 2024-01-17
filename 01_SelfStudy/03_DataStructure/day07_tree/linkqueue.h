#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

typedef bitree * datatype;

typedef struct node
{
    datatype data;
    struct node *next;
}listnode, *linklist;

typedef struct
{
    linklist front;
    linklist rear;
}linkqueue;

extern linkqueue *CreateQueue();
extern int EnQueue(linkqueue *lq, datatype x);
extern datatype DeQueue(linkqueue *lq);
extern int EmptyQueue(linkqueue *lq);
extern int ClearQueue(linkqueue *lq);
extern linkqueue *FreeQueue(linkqueue *lq);

#endif