#include "linkstack.h"

int main(int argc, char const *argv[])
{
    linkstack s = NULL;

    /* 创建栈 */
    s = CreateStack();
    if (s == NULL)
    {
        printf("Create faile\n");
        return -1;
    }

    /* 入栈 */
    PushStack(s, 10);
    PushStack(s, 20);
    PushStack(s, 30);
    PushStack(s, 40);

#if 0    
    /* 栈非空时出栈（注意出栈入栈顺序的不同） */
    while (!EmptyStack(s))
    {
        printf("pop: %d\n", PopStack(s));
    }
#endif 

    s = FreeStack(s);

    return 0;
}
