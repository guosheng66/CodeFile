#include "tree.h"
#include "linkqueue.h"

/*************************************
 * 函数名：*CreateQueue
 * 功能：创建队列
 * 参数：缺省
 * 返回值：
 *      成功返回创建的队列
 *      失败返回NULL
 * 注意事项：无
 *************************************/
linkqueue *CreateQueue()
{
    linkqueue *lq;

    lq = (linkqueue *)malloc(sizeof(linkqueue));
    if (NULL == lq)
    {
        perror("malloc failed");
        return NULL;
    }

    lq->front = lq->rear = (linklist)malloc(sizeof(listnode));
    if (NULL == lq->front)
    {
        printf("malloc node failed\n");
        return NULL;
    }

    lq->front->data = 0;
    lq->front->next = NULL;

    return lq;
}

/*************************************
 * 函数名：EnQueue
 * 功能：入队
 * 参数：
 *      linkqueue *lq:要添加数据的队列
 *      datatype value:要添加的数据
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 *************************************/
int EnQueue(linkqueue *lq, datatype value)
{
    linklist p = NULL;

    if (NULL == lq)
    {
        printf("lq is NULL(in EnQueue)\n");
        return -1;
    }

    p = (linklist)malloc(sizeof(listnode));
    if (NULL == p)
    {
        printf("malloc node failed\n");
        return -1;
    }

    p->data = value;
    p->next = NULL;

    lq->rear->next = p;
    lq->rear = p;

    return 0;
}

/*************************************
 * 函数名：DeQueue
 * 功能：出队
 * 参数：
 *      linkqueue *lq:要出队的队列
 * 返回值：
 *      成功返回队列节点数据指针
 *      失败返回空
 * 注意事项：无
 *************************************/
datatype DeQueue(linkqueue *lq)
{
    linklist p = NULL;

    if (NULL == lq)
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
    linklist p = NULL;

    if (NULL == lq)
    {
        printf("lq is NULL(in EmptyQueue)\n");
        return -1;
    }

    return (lq->front == lq->rear ? 1 : 0);
}

/************************************************
 * 函数名：ClearrQueue
 * 功能：清空队列
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