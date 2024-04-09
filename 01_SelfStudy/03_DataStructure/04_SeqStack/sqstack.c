#include "sqstack.h"

/***********************************************
 * 函数名：*CreateStack
 * 功能：创建一个栈
 * 参数：
 *      int len:栈中数据空间的长度（由用户定义）
 * 返回值：
 *      成功返回栈s
 *      失败返回NULL
 * 注意事项：无
 ***********************************************/
/*在这个函数中，返回一个指针是为了能够在堆上动态分配内存来创建一个新的栈对象。
  这样做的好处是，可以在函数外部使用这个栈对象，而不会因为函数调用结束而被销毁。
  具体来说：
  1.动态内存分配：
    函数内部通过调用 `malloc` 分配了一个 `sqstack` 结构体的内存空间，
    这个内存空间在堆上，因此不会随着函数调用结束而被释放，而是会一直存在，
    直到通过调用 `free` 来手动释放。
  2.返回值的使用：
    返回一个指向新创建的栈对象的指针，使得在函数外部可以通过这个指针来操作和管理这个栈对象。
    通常，调用者会将这个返回的指针存储在一个变量中，以便后续对栈进行操作。
    如果不使用指针，函数将只能返回一个结构体的副本，这意味着返回的将是一个新的
    栈对象的副本，而不是指向实际栈对象的指针。在这种情况下，对栈对象的修改只会影
    响到这个副本，而不会影响到原始的栈对象。
*/
sqstack *CreateStack(int len)
{
    sqstack *s;

    /* 申请栈空间 */
    s = (sqstack *)malloc(sizeof(sqstack));
    if (NULL == s)
    {
        perror("malloc sqstack failed(in CreateStack)");
        return NULL;
    }

    /* 申请存储数据的空间 */
    s->data = (data_t *)malloc(len * sizeof(data_t));
    if (NULL == s->data)
    {
        perror("malloc data failed(in CreateStack)");
        free(s);
        return NULL;
    }

    /* 初始化 */
    memset(s->data, 0, len * sizeof(data_t));
    s->maxlen = len;
    s->top = -1;

    return s;
}

/***********************************************
 * 函数名：PushStack
 * 功能：向栈中添加数据
 * 参数：
 *      sqstack s:要添加数据的栈
 *      data_t value:要添加的数据
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ***********************************************/
int PushStack(sqstack *s, data_t value)
{
    if (NULL == s)
    {
        printf("s is NULL(in PushStack)\n");
        return -1;
    }

    if (s->top == s->maxlen - 1)
    {
        printf("s is full(in PushStack)\n");
        return -1;
    }

    s->top++;
    s->data[s->top] = value;

    return 0;
}

/***********************************************
 * 函数名：PopStack
 * 功能：出栈
 * 参数：
 *      sqstack s:栈s
 * 返回值：
 *      成功返回栈顶数据
 * 注意事项：无
 ***********************************************/
int PopStack(sqstack *s)
{
    s->top--;

    return (s->data[s->top + 1]); //返回栈顶数据
}

/***********************************************
 * 函数名：EmptyStack
 * 功能：判断是否为空栈
 * 参数：
 *      sqstack *s:要进行判断的栈
 * 返回值：
 *      空栈返回0
 *      非空栈返回1
 * 注意事项：无
 ***********************************************/
int EmptyStack(sqstack *s)
{
    if (NULL == s)
    {
        printf("s is NULL(in EmptyStack)\n");
        return -1;
    }

    return (s->top == -1 ? 0 : 1);
}

/***********************************************
 * 函数名：FullStack
 * 功能：判断是否为满栈
 * 参数：
 *      sqstack *s:要进行判断的栈
 * 返回值：
 *      满栈返回1
 *      非满栈返回0
 * 注意事项：无
 ***********************************************/
int FullStack(sqstack *s)
{
    if (NULL == s)
    {
        printf("s is NULL(in FullStack)\n");
        return -1;
    }

    return (s->top == s->maxlen - 1 ? 1 : 0);
}

/***********************************************
 * 函数名：TopStack
 * 功能：查看栈顶
 * 参数：
 *      sqstack s:栈s
 * 返回值：
 *      成功返回栈顶数据
 * 注意事项：无
 ***********************************************/
int TopStack(sqstack *s)
{
    if (NULL == s)
    {
        printf("s is NULL(in TopStack)\n");
        return -1;
    }

    return (s->data[s->top + 1]);
}

/***********************************************
 * 函数名：ClearStack
 * 功能：清空栈
 * 参数：
 *      sqstack s:栈s
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ***********************************************/
int ClearStack(sqstack *s)
{
    if (NULL == s)
    {
        printf("s is NULL(in ClearStack)\n");
        return -1;
    }

    s->top == -1;

    return 0;
}

/***********************************************
 * 函数名：FreeStack
 * 功能：释放栈空间
 * 参数：
 *      sqstack s:栈s
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ***********************************************/
int FreeStack(sqstack *s)
{
    if (NULL == s)
    {
        printf("s is NULL(in FreeStack)\n");
        return -1;
    }

    /* 注意空间释放的顺序，防止出现内存泄漏
       如果先释放s，那么data的地址就找不到了
     */
    free(s->data);
    free(s);
    printf("Free successed\n");

    return 0;
}
