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
    linkqueue *lq = NULL; ////创建链式队列

    /* 队列空间申请失败打印提示信息并退出 */
    if ((lq = (linkqueue *)malloc(sizeof(linkqueue))) == NULL)
    {
        printf("malloc linkqueue failed\n");
        return NULL;
    }

    /* 头和尾指向一个单链表的头节点 */
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
int EnQueue(linkqueue *lq, datatype x)
{
    linklist p = NULL; //创建一个节点用于入队

    /* 如果为空队打印提示信息并退出 */
    if (lq == NULL)
    {
        printf("lq is NULL\n");
        return -1;
    }

    /* 链表节点空间申请失败打印提示信息并退出 */
    if ((p = (linklist)malloc(sizeof(listnode))) == NULL)
    {
        printf("malloc node failed\n");
        return -1;
    }

    p->data = x;    //将要插入的数据存储在节点p中
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
    linklist p = NULL; //创建一个节点

    /* 如果为空队打印提示信息并退出 */
    if (lq == NULL)
    {
        printf("lq is NULL\n");
        return -1;
    }

    p = lq->front;       //节点p指向待删除的位置
    lq->front = p->next; /* 指向头节点 */
    free(p);             //释放空间
    p = NULL;

    return (lq->front->data); //返回出队的数据（元素）
}

/******************************************
 * 函数名：EmptyQueue
 * 功能：判断是否为空队
 * 参数：
 *      linkqueue *lq:指向要插入数据的队列
 * 返回值：
 *      空队返回1
 *      非空队返0
 * 注意事项：无
 ******************************************/
int EmptyQueue(linkqueue *lq)
{
    /* 如果为空队打印提示信息并退出 */
    if (lq == NULL)
    {
        printf("lq is NULL");
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

    /* 如果为空队打印提示信息并退出 */
    if (lq == NULL)
    {
        printf("lq is NULL\n");
        return -1;
    }

    /* 清空队列和释放队列空间不同，清空队列会保留一个头节点 */
    while (lq->front->next)
    {
        p = lq->front;
        lq->front = p->next;
        printf("clear free: %d\n", p->data); //打印此次释放的节点
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

    /* 如果为空队打印提示信息并退出 */
    if (lq == NULL)
    {
        printf("lq is NULL\n");
        return NULL;
    }

    /* lq->front不为空的时候执行循环，释放后面节点所占的空间 */
    while (lq->front)
    {
        p = lq->front;
        lq->front = p->next;
        printf("free: %d\n", p->data);
        free(p);
    }

    free(lq);  //最后释放外层结构体
    lq = NULL; //更新调用链式队列的指针，防止误操作 | 用lq接收空指针
 
    return NULL;
}