#ifndef __SQLIST_H__
#define __SQLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 128
typedef int data_t; //定义一个数据结构

/* 两个部分结构体的定义相同，后面的较为简略 */
#if 0
struct sqlist_t
{
    data_t data_t[N];
    int last;
};
typedef struct sqlist_t sqlist;  //给创建的结构体起一个类型别名，便于后续操作
typedef struct sqlist_t *sqlink; 
#endif

typedef struct 
{
    data_t data[N]; //此处的数据结构自行定义
    int last;       //表中元素序号标识
}sqlist, *sqlink;

sqlink CreateList();
extern int ClearList(sqlink L);
extern int FreeList(sqlink L);
extern int IsEmptyList(sqlink L);
extern int LengthOfList(sqlink L);
extern int LocateList(sqlink L, data_t value);
extern int InsertList(sqlink L, data_t value, int pos);
extern int ShowList(sqlink L); 
extern int DeleteDataOfList(sqlink L, int pos);
extern int MergeList(sqlink L1, sqlink L2);
extern int PurgeList(sqlink L);

#endif
