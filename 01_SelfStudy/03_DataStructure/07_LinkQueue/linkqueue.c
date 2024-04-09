#include "linkqueue.h"

/******************************************
 * 函数名：CreateQueue
 * 功能：创建队列
 * 参数：
 *      缺省
 * 返回值：
 *      成功返回队列指针lq
 *      失败返回NULL
 * 注意事项：无
 ******************************************/
linkqueue *CreateQueue()
{
    linkqueue *lq = NULL;

    lq = (linkqueue *)malloc(sizeof(linkqueue));
    if (NULL == lq)
    {
        printf("malloc linkqueue failed\n");
        return NULL;
    }

    lq->front = lq->rear = (linklist)malloc(sizeof(listnode));
    
    if (NULL == lq->front)
    {
        printf("malloc node failed\n");
        return NULL;
    }

    /* 初始化 */
    lq->front->data = 0;
    lq->front->next = NULL;

    return lq;
}

/******************************************
 * 函数名：EnQueue
 * 功能：入队
 * 参数：
 *      linkqueue *lq:指向要插入数据的队列
 *      datatype x:要插入的数据（元素）
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ******************************************/
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

    /* 将节点p插入链表中 */
    lq->rear->next = p;
    lq->rear = p;

    return 0;    
}

/******************************************
 * 函数名：DeQueue
 * 功能：出队
 * 参数：
 *      linkqueue *lq:指向要插入数据的队列
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ******************************************/
datatype DeQueue(linkqueue *lq)
{
    linklist p = NULL;

    if (NULL == lq)
    {
        printf("lq is NULL(in DeQueue)\n");
        return -1;
    }

    p = lq->front; //节点p指向要删除的位置
    lq->front = p->next;
    free(p);
    p = NULL;

    return (lq->front->data);
}

/******************************************
 * 函数名：EmptyQueue
 * 功能：判断是否为空队
 * 参数：
 *      linkqueue *lq:指向要插入数据的队列
 * 返回值：
 *      空队返回1
 *      非空队返0
 *      失败返回-1
 * 注意事项：无
 ******************************************/
int EmptyQueue(linkqueue *lq)
{
    if (NULL == lq)
    {
        printf("lq is NULL(in EnQueue)\n");
        return -1;
    }

    return (lq->front == lq->rear ? 1 : 0);
}

/******************************************
 * 函数名：ClearQueue
 * 功能：清空队列
 * 参数：
 *      linkqueue *lq:指向要插入数据的队列
 * 返回值：
 *      成功返回1
 *      失败队返0
 * 注意事项：无
 ******************************************/
int ClearQueue(linkqueue *lq)
{
    linklist p = NULL;

    if (NULL == lq)
    {
        printf("lq is NULL(in ClearQueue)\n");
        return -1;
    }

    while (lq->front->next)
    {
        p = lq->front;
        lq->front = p->next;
        printf("clear free: %d\n", p->data);
        free(p);
        p = NULL;
    }

    return 0;
}

/******************************************
 * 函数名：*FreeQueue
 * 功能：释放队列空间（先释放内层，再释放外层）
 * 参数：
 *      linkqueue *lq:指向要插入数据的队列
 * 返回值：
 *      返回NULL
 * 注意事项：无
 ******************************************/
linkqueue *FreeQueue(linkqueue *lq)
{
    linklist p = NULL;

    if (NULL == lq)
    {
        printf("lq is NULL(in FreeQueue)\n");
        return NULL;
    }

    while (lq->front)
    {
        p = lq->front;
        lq->front = p->next;
        printf("free: %d\n", p->data);
        free(p);
    }

    free(lq);  //释放外层结构体
    lq = NULL;

    return NULL;
}