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

    /* 申请栈空间，失败打印提示信息并退出 */
    s = (linkstack)malloc(sizeof(listnode));
    if (s == NULL)
    {
        printf("malloc failed\n");
        return NULL;
    }

    /* 初始化（赋值） */
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
    linkstack p = NULL; //创建一个节点封装要入栈的元素（头部插入）

    /* 判断s是否为空栈，若为空打印提示信息并退出 */
    if (s == NULL)
    {
        printf("s is NULL\n");
        return -1;
    }

    /* 申请空间，失败打印提示信息并退出 */
    p = (linkstack)malloc(sizeof(listnode));
    if (p == NULL)
    {
        printf("malloc failed\n");
        return -1;
    }

    /* 将节点p插入栈中 */
    p->data = value;
    p->pNext = NULL; //连续赋值，此行不加上也可以
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
    data_t t = t;       //定义临时变量存储返回值（出栈的数据）

    /* 出栈，栈顶元素后移 */
    p = s->pNext;
    s->pNext = p->pNext;

    t = p->data; //存储要出栈的数据

    free(p);     //释放节点p所占据的空间
    p = NULL;

    return t;
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
    /* 判断s是否为空栈，若为空打印提示信息并退出 */
    if (s == NULL)
    {
        printf("s is NULL\n");
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
    /* 判断s是否为空栈，若为空打印提示信息并退出 */
    if (s == NULL)
    {
        printf("s is NULL\n");
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

    /* 判断s是否为空栈，若为空打印提示信息并退出 */
    if (s == NULL)
    {
        printf("s is NULL\n");
        return NULL;
    }

    /* 如果栈不为空，遍历栈中节点释放所占空间 */
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