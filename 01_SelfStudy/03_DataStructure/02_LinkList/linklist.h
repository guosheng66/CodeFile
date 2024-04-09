#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int data_t;

typedef struct node
{
    data_t data;
    struct node * pNext;
}listnode, *linklist;

extern linklist CreateList();
extern int InsertOfListEnd(linklist H, data_t value);
extern linklist GetList(linklist H, int pos);
extern int ShowList(linklist H);
extern int InsertList(linklist H, data_t value, int pos);
extern int DeleteList(linklist H, int pos);
extern linklist FreeList(linklist H);
extern void InsertTailTest();

extern void InsertTailTest();
extern void DeleteTest();
extern void FreeTest();

#endif