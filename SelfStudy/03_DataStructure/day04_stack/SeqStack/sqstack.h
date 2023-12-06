#ifndef __sqstack_H__
#define __sqstack_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int data_t; //定义栈中户数据元素的数据类型

typedef struct node 
{
    data_t *data; //用指针指向栈的存储空间
    int maxlen;   //当前占的最大元素个数（可由用户指定容量的大小）
    int top;      //指示栈顶位置（数组下表）的变量
}sqstack;         //顺序栈类型定义

extern sqstack *CreateStack(int len);
extern int PushStack(sqstack *s, data_t value);
extern data_t PopStack(sqstack *s);
extern int EmptyStack(sqstack *s);
extern int FullStack(sqstack *s);
extern data_t TopStack(sqstack *s);
extern int ClearStack(sqstack *s);
extern int FreeStack(sqstack *s);

#endif