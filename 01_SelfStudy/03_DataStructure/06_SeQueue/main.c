#include "sequeue.h"

int main(int argc, char const *argv[])
{
    sequeue *sq;

    sq = CreateQueue();
    if (NULL == sq)
    {
        printf("Create failed\n");
        return -1;
    }

    EnQueue(sq, 10);
    EnQueue(sq, 20);
    EnQueue(sq, 30);
    EnQueue(sq, 40);
    EnQueue(sq, 50);

    while (!EmptyQueue(sq))
    {
        printf("Dequeue: %d\n", DeQueue(sq));
    }

    FreeQueue(sq);

    return 0;
}
