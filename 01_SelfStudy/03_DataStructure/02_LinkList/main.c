#include "linklist.h"

int main(int argc, char const *argv[])
{
    // InsertTailTest();
    // DeleteTest();
    // FreeTest();

    return 0;
}

/*********************************************
 * 函数名：InsertTailTest
 * 功能：链表尾部数据插入测试
 * 参数：缺省
 * 返回值：无
 * 注意事项：无
 *********************************************/
void InsertTailTest()
{
    int value = 0;
    linklist H = NULL;
    linklist p = NULL;

    H = CreateList();
    if (NULL == H)
    {
        printf("CreateList failed\n");
        return;
    }

    while (1)
    {
        printf("input:");
        scanf("%d", &value);
        
        if (-1 == value)
        {
            break;
        }

        InsertOfListEnd(H, value);
    }

    ShowList(H);

    p = GetList(H, 6);
    if (p != NULL)
    {
        printf("value = %d\n", p->data);
    }

    FreeList(H);
}

/*********************************************
 * 函数名：DeleteTest
 * 功能：链表指定位置数据删除测试
 * 参数：缺省
 * 返回值：无
 * 注意事项：无
 *********************************************/
void DeleteTest()
{
    linklist H = NULL;

    H = CreateList();
    if (NULL == H)
    {
        printf("fail to create list\n");
        return;
    }

#if 0
    InsertList(H, 90, 0);
    InsertList(H, 80, 1);
    InsertList(H, 70, 2);
    InsertList(H, 60, 3);
    InsertList(H, 50, 4);
    InsertList(H, 40, 5);
    InsertList(H, 30, 6);
    InsertList(H, 20, 7);
    InsertList(H, 10, 8);
#endif
    
    InsertList(H, 80, 0);
    InsertList(H, 70, 0);
    InsertList(H, 60, 0);
    InsertList(H, 50, 0);
    InsertList(H, 40, 0);
    InsertList(H, 30, 0);
    InsertList(H, 20, 0);
    InsertList(H, 10, 0);

    printf("数据删除前的链表：\n");
    printf("===================================\n");
    ShowList(H);

    DeleteList(H, 2);

    printf("===================================\n");
    printf("数据删除后的链表：\n");
    printf("===================================\n");
    ShowList(H);
    
    DeleteList(H, 4); //注意该次删除操作，每次删除后链表是会发生变化的
                      //所以删除位置pos都是针对当前链表而言的

    printf("===================================\n");
    printf("数据删除后的链表：\n");
    printf("===================================\n");
    ShowList(H);

    FreeList(H);
}

/*********************************************
 * 函数名：FreeTest
 * 功能：清空链表
 * 参数：缺省
 * 返回值：无
 * 注意事项：无
 *********************************************/
void FreeTest()
{
    linklist H = NULL;

    H = CreateList();
    if (NULL == H)
    {
        printf("fail to create list\n");
        return;
    }

    InsertList(H, 80, 0);
    InsertList(H, 70, 0);
    InsertList(H, 60, 0);
    InsertList(H, 50, 0);
    InsertList(H, 40, 0);
    InsertList(H, 30, 0);
    InsertList(H, 20, 0);
    InsertList(H, 10, 0);

    printf("free前的链表：\n");
    printf("===================================\n");
    ShowList(H);

    H = FreeList(H); //释放链表空间
                     //H是一个形参，要么用二级指针传递H的地址，或者使用H接收返回值
                     //否则H不会改变

    printf("===================================\n");
    printf("free前的链表：\n");
    printf("===================================\n");
    printf("H: %p\n", H);
    ShowList(H);
}