#ifndef __SQLIST_H__
#define __SQLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN      128

typedef int data_t; //线性表的数据结构

typedef struct
{
    data_t data[MAXLEN]; //
    int last;            //最后一个元素在列表中的索引
}sqlist, *sqlink;

extern sqlink CreateList();
extern int ClearList(sqlink L);
extern int FreeList(sqlink L);
extern int EmptyList(sqlink L);
extern int LenOfList(sqlink L);
extern int LocateList(sqlink L, data_t value);
extern int InsertList(sqlink L, data_t value, int pos);
extern int ShowList(sqlink L);
extern int DeleteDataOfList(sqlink L, int pos);
extern int MergeList(sqlink L1, sqlink L2);
extern int PurgeList(sqlink L);

extern void DeleteTest();
extern void InsertTest();
extern void MergeTest();

#endif