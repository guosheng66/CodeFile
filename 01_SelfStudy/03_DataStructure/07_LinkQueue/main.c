#include "linkqueue.h"

int main(int argc, char const *argv[])
{
    linkqueue *lq = NULL;

    lq = CreateQueue();
    if (NULL == lq)
    {
        printf("CreateQueue failed\n");
        return -1;
    }

    EnQueue(lq, 10);
    EnQueue(lq, 20);
    EnQueue(lq, 30);
    EnQueue(lq, 40);
    
    while (!EmptyQueue(lq))
    {
        printf("queue: %d\n", DeQueue(lq));
    }

    // ClearQueue(lq);
    FreeQueue(lq);

    return 0;
}
