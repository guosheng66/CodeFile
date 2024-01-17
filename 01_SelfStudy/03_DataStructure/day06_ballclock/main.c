#include <stdio.h>
#include "linkqueue.h"
#include "sqstack.h"

int Check(linkqueue *lq);

int main(int argc, char const *argv[])
{
    linkqueue *lq = NULL;   //创建队列存放所有球
    sqstack *s_hour = NULL; //小时栈
    sqstack *s_five = NULL; //五分钟栈
    sqstack *s_min = NULL;  //分钟栈
    int value = 0;          //存储出队的数值
    int i = 0;              //辅助变量，循环使用
    int min = 0;            //分钟变量，用于计时

    /* 创建队列失败打印提示信息并退出程序 */
    if ((lq = CreateQueue()) == NULL)
    {
        printf("CreatQueue failed\n");
        return -1;
    }

    /* 27个球，循环入队 */
    for (i =1; i <= 27; i++)
    {
        EnQueue(lq, i);
    }

    /* 栈创建失败打印提示信息并退出 */
    if ((s_hour = CreateStack(11)) == NULL)
    {
        printf("CreateStack failed\n");
        return -1;
    }

    /* 栈创建失败打印提示信息并退出 */
    if ((s_five = CreateStack(11)) == NULL)
    {
        printf("CreateStack failed\n");
        return -1;
    }

    /* 栈创建失败打印提示信息并退出 */
    if ((s_min = CreateStack(4)) == NULL)
    {
        printf("CreateStack failed\n");
        return -1;
    }

    /* 模拟球钟运行过程 */
    while (1)
    {
        min++;
        
        /* 当队列不为空的时候出队 */
        if (!EmptyQueue(lq))
        {
            value = DeQueue(lq); //出队

            /* 分钟指示器不为满的时候将出队的数据入栈 */
            if (!FullStack(s_min))
            {
                PushStack(s_min, value);
            }
            else
            {
                /* 当分钟指示器不为空即还有球，就将分钟指示器中的数值按照入栈时
                 * 相反的顺序出栈，放入队列中去
                 */
                while (!EmptyStack(s_min))
                {
                    EnQueue(lq, PopStack(s_min)); //入队 
                }

                /* 五分钟指示器不为满的时候将出队的数据入栈 */
                if (!FullStack(s_five))
                {
                    PushStack(s_five, value);
                }
                else
                {
                    /* 当五分钟指示器不为空即还有球，就将五分钟指示器中的数值按照入栈时
                     * 相反的顺序出栈，放入队列中去
                     */
                    while (!EmptyStack(s_five))
                    {
                        EnQueue(lq, PopStack(s_five));
                    }    
                    
                    /* 小时指示器不为满的时候将出队的数据入栈 */
                    if (!FullStack(s_hour))
                    {
                        PushStack(s_hour, value);
                    }
                    else
                    {
                        /* 当小时指示器不为空即还有球，就将小时指示器中的数值按照入栈时
                         * 相反的顺序出栈，放入队列中去
                         */
                        while (!EmptyStack(s_hour))
                        {
                            EnQueue(lq, PopStack(s_hour));
                        }

                        EnQueue(lq, value); //此时时间为00:00

                        /* 队列升序（有序）退出循环 */
                        if (Check(lq) == 1)
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    
    printf("total: %d\n", min);

    printf("DeQueue:");
    while (!EmptyQueue(lq))
    {
        printf("%d ", DeQueue(lq));
    }
    puts("");

    printf("");

    /* 释放空间 */
    FreeQueue(lq);
    FreeStack(s_hour);
    FreeStack(s_five);
    FreeStack(s_min);

    return 0;
}

/**************************************************
 * 函数名：Check
 * 功能：检验队列是否有序，是否为升序
 * 参数：
 *      linkqueue *lq:队列lq
 * 返回值：
 *      升序返回1
 *      不是升序返回0
 * 注意事项：无
 **************************************************/
int Check(linkqueue *lq)
{
    linklist p = NULL;

    /* 队列为空打印提示信息并退退出 */
    if (lq == NULL)
    {
        printf("lq is NULL\n");
        return - 1;
    }

    p = lq->front->next; //p指向队列第一个节点

    /* p和p->next均不为空进行比较 */
    while (p && p->next)
    {
        if (p->data < p->next->data)
        {
            p = p->next;
        }
        else
        {
            return 0; //队列不是升序直接返回0
        }
    }

    return 1;
}