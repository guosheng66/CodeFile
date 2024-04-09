#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node
{
    datatype data;
    struct node *next;
}listnode, *linklist;

typedef struct
{
    linklist front; //头指针
    linklist rear;  //尾指针
}linkqueue;

extern linkqueue *CreateQueue(); //这次创建队列是创建linkqueue，而不是链表的一个节点
extern int EnQueue(linkqueue *lq, datatype x);
extern datatype DeQueue(linkqueue *lq);
extern int EmptyQueue(linkqueue *lq);
extern int ClearQueue(linkqueue *lq);
extern linkqueue *FreeQueue(linkqueue *lq);

#endif