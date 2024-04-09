#include "linkstack.h"

/***********************************************
 * 函数名：CreateStack
 * 功能：创建栈
 * 参数：
 *      缺省
 * 返回值：
 *      成功返回创建的栈
 *      失败返回NULL
 * 注意事项：无
 ***********************************************/
linkstack CreateStack()
{
    linkstack s = NULL;

    s = (linkstack)malloc(sizeof(listnode));
    if (NULL == s)
    {
        perror("malloc failed(in CreateStack)");
        return NULL;
    }

    /* 初始化 */
    s->data = 0;
    s->pNext = NULL;

    return s;
}

/***********************************************
 * 函数名：PushStack
 * 功能：入栈
 * 参数：
 *      linkstack s:栈s
 *      data_t value:要插入的数据
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ***********************************************/
int PushStack(linkstack s, data_t value)
{
    linkstack p = NULL;

    if (NULL == s)
    {
        printf("s is NULL(in PushStack)\n");
        return -1;
    }

    p = (linkstack)malloc(sizeof(listnode));
    if (NULL == p)
    {
        printf("malloc lisnode failed(in PushStack)\n");
        return -1;
    }

    /* 将节点插入栈中 */
    p->data = value;
    p->pNext = NULL;
    p->pNext = s->pNext;
    s->pNext = p;

    return 0;
}

/***********************************************
 * 函数名：PopStack
 * 功能：出栈
 * 参数：
 *      linkstack s:栈s
 *      data_t value:要插入的数据
 * 返回值：
 *      成功返回出栈的数据
 * 注意事项：无
 ***********************************************/
data_t PopStack(linkstack s)
{
    linkstack p = NULL;
    data_t temp; //定义临时变量存储返回值（出栈的数据）

    /* 出栈，栈顶元素后移 */
    p = s->pNext;
    s->pNext = p->pNext;

    temp = p->data;

    free(p);
    p = NULL;

    return temp;
}

/***********************************************
 * 函数名：EmptyStack
 * 功能：判断是否为空栈
 * 参数：
 *      linkstack s:栈s
 * 返回值：
 *      为空栈返回1
 *      不为空栈返回0
 *      失败返回-1
 * 注意事项：无
 ***********************************************/
int EmptyStack(linkstack s)
{
    if (NULL == s)
    {
        printf("s is NULL(in EmptyStack)\n");
        return -1;
    }

    return (s->pNext == NULL ? 1 : 0);
}

/***********************************************
 * 函数名：TopStack
 * 功能：返回栈顶元素
 * 参数：
 *      linkstack s:栈s
 * 返回值：
 *      成功返回栈顶元素
 *      失败返回-1
 * 注意事项：无
 ***********************************************/
data_t TopStack(linkstack s)
{
    if (NULL == s)
    {
        printf("s is NULL(in TopStack)\n");
        return -1;
    }

    return (s->pNext->data);
}

/***********************************************
 * 函数名：FreeStack
 * 功能：释放栈空间
 * 参数：
 *      linkstack s:栈s
 * 返回值：
 *      返回NULL
 * 注意事项：无
 ***********************************************/
linkstack FreeStack(linkstack s)
{
    linkstack p = NULL;

    if (NULL == s)
    {
        printf("s is NULL(in FreeStack)\n");
        return NULL;
    }

    while (s != NULL)
    {
        p = s;
        s = s->pNext;
        printf("free: %d\n", p->data);
        free(p);
    }

    printf("Free successed\n");

    return NULL;
}