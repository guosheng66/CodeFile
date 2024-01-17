#include "sqstack.h"

int main(int argc, char const *argv[])
{
    sqstack *s = NULL;

    s = CreateStack(100); //创建一个顺序栈
    /* 栈创建失败打印提示信息并退出 */
    if (s == NULL)
    {
        printf("fail to Create\n");
        return -1;
    }
    
    /* 入栈 */
    PushStack(s, 10);
    PushStack(s, 20);
    PushStack(s, 30);
    PushStack(s, 40);
    PushStack(s, 50);

    /* 当栈不为空的时候继续执行后续操作 */
    while (EmptyStack(s))
    {
        printf("pop:%d\n", PopStack(s)); //注意观察此处出栈数据的顺序与入栈数据的不同
    }

    FreeStack(s);

    return 0;
}
