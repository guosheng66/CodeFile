#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 15

typedef int datatype;

/* 哈希表节点定义 */
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
extern int InsertHash(hash *ht, datatype key);
extern linklist SearchHash(hash *ht, datatype key);

#endif