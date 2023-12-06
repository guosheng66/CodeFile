#include "sequeue.h"

int main(int argc, char const *argv[])
{
    sequeue *sq = NULL; //定义一个队列变量

    /* 队列创建失败打印提示信息并退出 */
    if ((sq = CreateQueue()) == NULL)
    {
        printf("Create faiiled\n");
        return -1;
    }

    /* 向队列中插入数据 */
    EnQueue(sq, 10);
    EnQueue(sq, 100);
    EnQueue(sq, 1000);
    EnQueue(sq, 10000);
    
    while (!EmptyQueue(sq))
    {
        printf("Dequeue: %d\n", DeQueue(sq));
    }

    FreeQueue(sq);

    return 0;
}
