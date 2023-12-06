#include "linkqueue.h"

int main(int argc, char const *argv[])
{
    linkqueue *lq = NULL; //创建链式队列

    lq =CreateQueue();
    /* 如果队列创建失败打印提示信息并退出 */
    if (lq == NULL)
    {
        printf("Create failed\n");
        return -1;
    }

    /* 入队 */
    EnQueue(lq, 10);
    EnQueue(lq, 20);
    EnQueue(lq, 30);
    EnQueue(lq, 40);
    EnQueue(lq, 50);

#if 0
    /* 当队列不为空的时候，出队 */
    while (!EmptyQueue(lq))
    {
        printf("DeQueue: %d\n", DeQueue(lq));
    }
#endif

    //ClearQueue(lq);

    lq = FreeQueue(lq);

    EnQueue(lq, 10);
    
    return 0;
}
