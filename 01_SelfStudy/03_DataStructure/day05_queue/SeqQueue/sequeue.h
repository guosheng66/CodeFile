#ifndef __SEQUEUE_H__
#define __SEQUEUE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 128         //定义队列的容量

typedef int datatype; //定义队列中数据元素的数据类型

typedef struct
{
    datatype data[N]; //用数组作为队列的储存空间
    int front;        //队头
    int rear;         //队尾
}sequeue;             //顺序队列类型定义

extern sequeue *CreateQueue();
extern int EnQueue(sequeue *sq, datatype x);
extern datatype DeQueue(sequeue *sq);
extern int EmptyQueue(sequeue *sq);
extern int FullQueue(sequeue *sq);
extern int ClearQueue(sequeue *sq);
extern sequeue *FreeQueue(sequeue *sq);

#endif