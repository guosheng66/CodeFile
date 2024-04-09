#ifndef __SQSTACK_H__
#define __SQSRACK_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int data_t;

typedef struct node
{
    data_t *data; //定义指针指向栈的存储空间
    int maxlen;   //
    int top;      //指示栈顶位置
}sqstack;

extern sqstack *CreateStack(int len);
extern int PushStack(sqstack *s, data_t value);
extern int PopStack(sqstack *s);
extern int EmptyStack(sqstack *s);
extern int FullStack(sqstack *s);
extern int TopStack(sqstack *s);
extern int ClearStack(sqstack *s);
extern int FreeStack(sqstack *s);

#endif