#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <stdlib.h>

typedef char data_t; //定义数据元素类型

typedef struct node_t
{
    data_t data;          //数据元素
    struct node_t *left;  //二叉树左指针
    struct node_t *right; //二叉树右指针
}bitree; 

extern bitree *CreateTree();
extern void PreOrder(bitree *r);
extern void InOrder(bitree *r);
extern void PostOrder(bitree *r);
extern void LayerOrder(bitree *r);

#endif