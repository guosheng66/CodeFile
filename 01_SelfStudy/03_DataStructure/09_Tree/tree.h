#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <stdlib.h>

typedef char data_t;

typedef struct node_t
{
    data_t data;
    struct node_t *left;
    struct node_t *right;
}bitree;

extern bitree *CreateTree();
extern void PreOrder(bitree *r);
extern void InOrder(bitree *r);
extern void LayerOrder(bitree *r);
extern void PostOrder(bitree *r);

#endif