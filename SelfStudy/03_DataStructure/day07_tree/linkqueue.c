#include "linkqueue.h"
#include "tree.h"

/************************************************
 * 函数名：*CreateQueue
 * 功能：创建一个链表
 * 参数：
 *      缺省
 * 返回值：
 *      成功返回创建的队列lq
 *      失败返回NULL
 * 注意事项：无
 ************************************************/
linkqueue *CreateQueue()
{
    linkqueue *lq = NULL;
    
    /* 队列创建失败打印提示信息并退出 */
    if ((lq = (linkqueue *)malloc(sizeof(linkqueue))) == NULL)
    {
        printf("malloc linkqueue failed\n");
        return NULL;
    }

    /* 申请节点空间 */
    lq->front = lq->rear = (linklist)malloc(sizeof(listnode));
    /* 节点空间申请失败打印提示信息并退出 */
    if (lq->front == NULL)
    {
        printf("malloc node failed\n");
        return NULL;
    }

    /* 初始化 */
    lq->front->data = 0;
    lq->front->next = NULL;

    return lq;
}

/************************************************
 * 函数名：EnQueue
 * 功能：（队尾）数据元素插入
 * 参数：
 *      linkqueue *lq:队列lq
 *      datatype x:要插入的数据元素
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ************************************************/
int EnQueue(linkqueue *lq, datatype x)
{
    linklist p = NULL;

    /* 队列为空打印提示信息并退出 */
    if (lq == NULL)
    {
        printf("lq is NULL");
        return -1;
    }

    /* 节点空间申请失败打印提示信息并退出 */
    if ((p = (linklist)malloc(sizeof(listnode))) == NULL)
    {
        printf("malloc node failed\n");
        return -1;
    }

    /* 新节点存储要插入的数据元素 */
    p->data = x;
    p->next = NULL;

    /* 将新的节点插入到队列尾部 */
    lq->rear->next = p;
    lq->rear = p;

    return 0;
}

/************************************************
 * 函数名：DeQueue
 * 功能：出队
 * 参数：
 *      linkqueue *lq:队列lq
 * 返回值：
 *      成功返回出队的数据元素
 *      失败返回NULL
 * 注意事项：无
 ************************************************/
datatype DeQueue(linkqueue *lq)
{
    linklist p = NULL;
    
    /* 队列为空打印提示信息并退出 */
    if (lq == NULL)
    {
        printf("lq is NULL\n");
        return NULL;
    }

    p = lq->front;
    lq->front = p->next;
    free(p);
    p = NULL;

    return (lq->front->data);
}

/************************************************
 * 函数名：EmptyQueue
 * 功能：判断队列是否为空
 * 参数：
 *      linkqueue *lq:队列lq
 * 返回值：
 *      空队返回1
 *      非空队返回0
 *      失败返回-1
 * 注意事项：无
 ************************************************/
int EmptyQueue(linkqueue *lq)
{
    /* 队列为空打印提示信息并退出 */
    if (lq == NULL)
    {
        printf("lq is NULL\n");
        return -1;
    }

    return (lq->front == lq->rear ? 1 : 0);
}

/************************************************
 * 函数名：EmptyQueue
 * 功能：判断队列是否为空
 * 参数：
 *      linkqueue *lq:队列lq
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ************************************************/
int ClearQueue(linkqueue *lq)
{
    linklist p = NULL;

    /* 队列为空打印提示信息并退出 */
    if (lq == NULL)
    {
        printf("lq is NULL\n");
        return -1;
    }

    /* 队列节点不为空循环释放节点空间 */
    while (lq->front->next)
    {
        p = lq->front;
        lq->front = p->next;

        free(p);
        p = NULL;
    }

    return 0;
}

/************************************************
 * 函数名：FreeQueue
 * 功能：释放队列空间
 * 参数：
 *      linkqueue *lq:队列lq
 * 返回值：
 *      返回NULL
 * 注意事项：无
 ************************************************/
linkqueue *FreeQueue(linkqueue *lq)
{
    linklist p = NULL;

    if (lq == NULL)
    {
        printf("lq is NULL\n");
        return NULL;
    }

    while (lq->front)
    {
        p = lq->front;
        lq->front = p->next;
        
        free(p);
    }

    free(lq);
    lq = NULL;

    return NULL;
}