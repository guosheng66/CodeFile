#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int data_t;

typedef struct node
{
    data_t data;
    struct node *pNext;
}listnode, *linkstack;

extern linkstack CreateStack();
extern int PushStack(linkstack s, data_t value);
extern int PushStack(linkstack s, data_t value);
extern data_t PopStack(linkstack s);
extern int EmptyStack(linkstack s);
extern data_t TopStack(linkstack s);
extern linkstack FreeStack(linkstack s);


#endif