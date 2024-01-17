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
    sequeue *sq = NULL; //定义一个队列变量

    /* 给队列申请空间，申请失败打印提示信息并退出 */
    if ((sq = (sequeue *)malloc(sizeof(sequeue))) == NULL)
    {
        printf("malloc failed\n");
        return NULL;
    }

    /* 队列初始化（赋值） */
    memset(sq->data, 0, sizeof(sq->data)); //将队列的数据域置0
    sq->front = sq->rear = 0;             //队头 = 队尾 = (0 ～ n-1)（空队）
    
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
    /* 判断队列是否为空，为空打印提示信息并退出 */
    if (sq == NULL)
    {
        printf("sq is NULL\n");
        return -1;
    }

    /* 判断队列是否为满队，为满打印提示信息并退出 */
    if ((sq->rear + 1) % N == sq->front)
    {
        printf("sequeue is full\n");
        return -1;
    }

    /* 数据插入 */
    sq->data[sq->rear] = x;
    sq->rear = (sq->rear + 1) % N; //并不是sq->rear++,是++后取余

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
    datatype ret = 0; //存储要出队（删除）的数据

    /* 判断队列是否为空，为空打印提示信息并退出 */
    if (sq == NULL)
    {
        printf("sq is NULL\n");
        return -1;
    }


    ret = sq->data[sq->front];       //将要出队（删除）的数据存储在ret中
    sq->front = (sq->front + 1) % N; //更新front,同入队时rear的更新
 
    return ret;      //注意此处返回的数据类型
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
    /* 判断队列是否为空，为空打印提示信息并退出 */
    if (sq == NULL)
    {
        printf("sq is NULL\n");
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
    /* 判断队列是否为空，为空打印提示信息并退出 */
    if (sq == NULL)
    {
        printf("sq is NULL\n");
        return -1;
    }

    if ((sq->rear + 1) % N == sq->front)
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
    /* 判断队列是否为空，为空打印提示信息并退出 */
    if (sq == NULL)
    {
        printf("sq is NULL\n");
        return -1;
    }

    sq->front  = sq->rear = 0; //空队，队头 = 队尾

    return 0;
}

/******************************************
 * 函数名：ClearQueue
 * 功能：清除队列
 * 参数：
 *      sequeue *sq:指向队列sq的指针
 * 返回值：
 *      成功返回NULl
 * 注意事项：无
 ******************************************/
sequeue *FreeQueue(sequeue *sq)
{
    /* 判断队列是否为空，为空打印提示信息并退出 */
    if (sq == NULL)
    {
        printf("sq is NULL\n");
        return NULL;
    }

    free(sq);  //释放队列空间
    sq = NULL; //将队列置空

    printf("Free Successed\n");

    return NULL;
}