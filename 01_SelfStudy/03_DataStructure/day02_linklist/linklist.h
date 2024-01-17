#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef int data_t;

typedef struct node
{
    data_t data;        //节点的数据域
    struct node *pNext; //节点的后继指针域，指向下一个节点
}listnode, *linklist;

extern linklist CreateList();
extern int InsertTailOfList(linklist H, data_t value);
extern linklist GetList(linklist H, int pos);
extern int ShowList(linklist H);
extern int InsertList(linklist H, data_t value, int pos);
extern int DeleteList(linklist H, int pos);
extern linklist FreeList(linklist H);

#endif
