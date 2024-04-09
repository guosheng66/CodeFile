#include "linkstack.h"

int main(int argc, char const *argv[])
{
    linkstack s = NULL;

    s = CreateStack();
    if (NULL == s)
    {
        printf("Create failed\n");
        return -1;
    }

    PushStack(s, 10);
    PushStack(s, 20);
    PushStack(s, 30);
    PushStack(s, 40);
    PushStack(s, 50);

    while (!EmptyStack(s))
    {
        printf("pop: %d\n", PopStack(s));
    }

    s = FreeStack(s);
    
    return 0;
}
