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
sqstack *CreateStack(int len)
{
    sqstack *s = NULL; //创建栈结构体类型

    /* 申请栈的空间，失败打印提示信息并退出 */
    if ((s = (sqstack *)malloc(sizeof(sqstack))) == NULL)
    {
        printf("malloc sqstack failed\n");
        return NULL;
    }

    /* 申请栈存储数据的空间 */
    if ((s->data = (data_t *)malloc(len * sizeof(data_t))) == NULL)
    {
        printf("malloc data failed\n");
        free(s); //释放栈申请的空间
        return NULL;
    }

    /* 初始化（赋初值） */
    memset(s->data, 0, len * sizeof(data_t)); //栈中所有元素清零
    s->maxlen = len;                          //栈最大元素个数赋值
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
    /* 判断s是否为空栈（未创建成功的，并非没有存储数据的） */
    if (s == NULL)
    {
        printf("s is NULL\n");
        return -1;
    }

    /* 如果满栈不能继续添加数据，打印提示信息并退出 */
    if (s->top == s->maxlen - 1)
    {
        printf("stck is full\n");
        return -1;
    }

    /* 初始化（赋值） */
    s->top++;                //记录栈中数据个数
    s->data[s->top] = value; //将数据存储在相应的空间

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
    s->top--; //要将下一个元素作为栈顶，进行自检

    return (s->data[s->top + 1]); //返回栈顶数据
}

/***********************************************
 * 函数名：FullStack
 * 功能：判断是否为空栈
 * 参数：
 *      sqstack s:要进行判断的栈
 * 返回值：
 *      空栈返回1
 *      非空栈返回0
 * 注意事项：无
 ***********************************************/
int EmptyStack(sqstack *s)
{
    /* 判断s是否为空栈（未创建成功的，并非没有存储数据的） */
    if (s == NULL)
    {
        printf("s is NULL\n");
        return -1;
    }

    /* 根据top的值判断是否为空栈 */
    return (s->top == -1 ? 1 : 0);
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
    /* 判断s是否为空栈（未创建成功的，并非没有存储数据的） */
    if (s == NULL)
    {
        printf("s is NULL\n");
        return -1;
    }

    return (s->top == s->maxlen-1 ? 1 : 0);
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
    /* 判断s是否为空栈（未创建成功的，并非没有存储数据的） */
    if (s == NULL)
    {
        printf("s is NULL\n");
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
    /* 判断s是否为空栈（未创建成功的，并非没有存储数据的） */
    if (s == NULL)
    {
        printf("s is NULL\n");
        return -1;
    }
    
    s->top = -1;

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
    /* 判断s是否为空栈（未创建成功的，并非没有存储数据的） */
    if (s == NULL)
    {
        printf("s is NULL\n");
        return -1;
    }

    /*******************************************
     * 注意空间释放的顺序，防止出现内存泄漏
     * 如果先释放s,那么data的地址就找不到了
     *******************************************/
    free(s->data);
    free(s); 
    printf("Free successed\n");

    return 0;
}