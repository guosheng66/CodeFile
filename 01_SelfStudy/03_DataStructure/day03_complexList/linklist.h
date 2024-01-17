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
//listnode表示节点的类型
//*linklist表示指向listnode节点类型的指针

extern linklist CreateList();
extern int InsertTailOfList(linklist H, data_t value);
extern linklist GetList(linklist H, int pos);
extern int ShowList(linklist H);
extern int InsertList(linklist H, data_t value, int pos);
extern int DeleteList(linklist H, int pos);
extern linklist FreeList(linklist H);
extern int ReverseList(linklist H);
extern linklist MaxOfAdjNodes(linklist H, data_t *value);
extern int MergeList(linklist H1, linklist H2);

#endif
