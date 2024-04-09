#include "sequeue.h"

/******************************************
 * 函数名：CreateQueue
 * 功能：创建队列
 * 参数：
 *      缺省
 * 返回值：
 *      成功返回队列sq
 *      失败返回空
 * 注意事项：无
 ******************************************/
sequeue *CreateQueue()
{
    sequeue *sq = NULL;

    sq = (sequeue *)malloc(sizeof(sequeue));
    if (NULL == sq)
    {
        printf("malloc failed\n");
        return NULL;
    }

    /* 队列初始化 */
    memset(sq->data, 0, sizeof(sq->data));
    sq->front = sq->rear = 0; //队头 = 队尾 = (0 ~ n - 1) （空队）

    return sq;
}

/******************************************
 * 函数名：EnQueue
 * 功能：入队
 * 参数：
 *      sequeue *sq:指向队列sq的指针
 *      datatype x:要插入的数据
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ******************************************/
int EnQueue(sequeue *sq, datatype x)
{
    if (NULL == sq)
    {
        printf("sq is NULL(in EnQueue)");
        return -1;
    }

    if ((sq->rear + 1) % MAXLEN == sq->front)
    {
        printf("sequeue is full(EnQueue)\n");
        return -1;
    }

    /* 数据插入 */
    sq->data[sq->rear] = x;
    sq->rear = (sq->rear + 1) % MAXLEN;

    return 0;
}

/******************************************
 * 函数名：DeQueue
 * 功能：出队
 * 参数：
 *      sequeue *sq:指向队列sq的指针
 * 返回值：
 *      成功返回出队的数据
 *      失败返回-1
 * 注意事项：无
 ******************************************/
datatype DeQueue(sequeue *sq)
{
    datatype ret = 0;

    if (NULL == sq)
    {
        printf("s is NULL(in DeQueue)\n");
        return -1;
    }

    ret = sq->data[sq->front];
    sq->front = (sq->front + 1) % MAXLEN; //这行代码是用来更新队头位置，以便指向队列中的下一个元素

    return ret;
}

/******************************************
 * 函数名：EmptyQueue
 * 功能：判断队列是否为空
 * 参数：
 *      sequeue *sq:指向队列sq的指针
 * 返回值：
 *      空队返回0
 *      空队返回1
 * 注意事项：无
 ******************************************/
int EmptyQueue(sequeue *sq)
{
    if (NULL == sq)
    {
        printf("sq is NULL(in EmptyQueue)\n");
        return -1;
    }

    return (sq->front == sq->rear ? 1 : 0);
}

/******************************************
 * 函数名：FullQueue
 * 功能：判断队列是否为满
 * 参数：
 *      sequeue *sq:指向队列sq的指针
 * 返回值：
 *      满队返回0
 *      满队返回1
 * 注意事项：无
 ******************************************/
int FullQueue(sequeue *sq)
{
    if (NULL == sq)
    {
        printf("sq is NULL(in FullQueue)\n");
        return -1;
    }

    if ((sq->rear + 1) % MAXLEN == sq->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/******************************************
 * 函数名：ClearQueue
 * 功能：清除队列
 * 参数：
 *      sequeue *sq:指向队列sq的指针
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ******************************************/
int ClearQueue(sequeue *sq)
{
    if (NULL == sq)
    {
        printf("sq is NULL(in CLearQueue)\n");
        return -1;
    }

    sq->front = sq->rear = 0; //空队：队头 = 队尾

    return 0;
}

/******************************************
 * 函数名：FreeQueue
 * 功能：释放队列空间
 * 参数：
 *      sequeue *sq:指向队列sq的指针
 * 返回值：
 *      返回NULL
 * 注意事项：无
 ******************************************/
sequeue *FreeQueue(sequeue *sq)
{
    if (NULL == sq)
    {
        printf("sq is NULL\n");
        return NULL;
    }

    free(sq);
    sq = NULL;

    printf("Free Successed\n");

    return NULL;
}