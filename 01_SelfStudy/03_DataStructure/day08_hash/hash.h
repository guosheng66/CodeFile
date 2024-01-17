#ifndef __HAHS_H__
#define __HAHS_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 15

typedef int datatype; //定义数据类型

/* 哈希表单个结点定义 */
typedef struct node
{
    datatype key;
    datatype value;
    struct node *next;
}listnode, *linklist;

/* 定义哈希结构 */
typedef struct
{
    listnode data[N];
}hash;

extern hash *CreateHash();
extern int InsertHash(hash *HT, datatype key);
extern linklist SearchHash(hash *HT, datatype key);

#endif