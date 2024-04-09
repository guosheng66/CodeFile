#include "sqstack.h"

int main(int argc, char const *argv[])
{
    sqstack *s = NULL;


    s = CreateStack(100);
    if (NULL == s)
    {
        printf("fail to create stack\n");
        return -1;
    }

    PushStack(s, 10);
    PushStack(s, 20);
    PushStack(s, 30);
    PushStack(s, 40);
    PushStack(s, 50);

    while (EmptyStack(s))
    {
        printf("pop: %d\n", PopStack(s));
    }

    FreeStack(s);
    
    return 0;
}
