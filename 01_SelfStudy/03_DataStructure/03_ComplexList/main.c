#include "linklist.h"

int main(int argc, char const *argv[])
{
    // InsertTailTest();
    // DeleteTest();
    // FreeTest();
    // ReverseTest();
    // SumTest();
    // MergeTest();
    PurgeTest();

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

    FreeList(H);
}

/*********************************************
 * 函数名：ReverseTest
 * 功能：实现链表反转
 * 参数：缺省
 * 返回值：无
 * 注意事项：无
 *********************************************/
void ReverseTest()
{
    linklist H = NULL;

    H = CreateList();
    if (NULL == H)
    {
        printf("H is NULL\n");
        return;
    }

    InsertList(H, 60, 0);
    InsertList(H, 50, 0);
    InsertList(H, 40, 0);
    InsertList(H, 30, 0);
    InsertList(H, 20, 0);
    InsertList(H, 10, 0);

    printf("===================================\n");
    printf("反转前的链表：\n");
    printf("===================================\n");

    ShowList(H);
    ReverseList(H);

    printf("===================================\n");
    printf("反转后的链表：\n");
    printf("===================================\n");
    ShowList(H);

    FreeList(H);
}

/*********************************************
 * 函数名：SumTest
 * 功能：求链表相邻节点和的最大值
 * 参数：缺省
 * 返回值：无
 * 注意事项：无
 *********************************************/
void SumTest()
{
    int max = 0;
    linklist H;
    linklist r;

    H = CreateList();
    if (NULL == H)
    {
        printf("H is NULL");
        return;
    }

    InsertList(H, 70, 0);
    InsertList(H, 60, 0);
    InsertList(H, 50, 0);
    InsertList(H, 40, 0);
    InsertList(H, 30, 0);
    InsertList(H, 20, 0);
    InsertList(H, 10, 0);

    printf("打印链表：\n");
    ShowList(H);

    r = MaxOfAdjNodes(H, &max);
    printf("max sum: %d\n", max);
    
    FreeList(H);
}

/*********************************************
 * 函数名：MergeTest
 * 功能：链表有序链表合并测试
 * 参数：缺省
 * 返回值：无
 * 注意事项：无
 *********************************************/
void MergeTest()
{
    linklist H1;
    linklist H2;

    H1 = CreateList();
    if (NULL == H1)
    {
        printf("H1 is NULL\n");
        return;
    }

    H2 = CreateList();
    if (NULL == H2)
    {
        printf("H1 is NULL\n");
        return;
    }

    printf("============================================\n");
    printf("合并前的链表：\n");
    printf("============================================\n");

    InsertList(H1, 50, 0);
    InsertList(H1, 40, 0);
    InsertList(H1, 30, 0);
    InsertList(H1, 20, 0);
    InsertList(H1, 10, 0);

    InsertList(H2, 70, 0);
    InsertList(H2, 60, 0);
    InsertList(H2, 50, 0);
    InsertList(H2, 40, 0);

    ShowList(H1);
    ShowList(H2);       

    printf("============================================\n");
    printf("合并后的链表：\n");
    printf("============================================\n");

    MergeList(H1, H2);
    
    ShowList(H1);
    ShowList(H2);

    FreeList(H1);
    FreeList(H2);
}

/*********************************************
 * 函数名：PurgeTest
 * 功能：删除链表中的重复数据元素
 * 参数：缺省
 * 返回值：无
 * 注意事项：无
 *********************************************/
void PurgeTest()
{
    linklist H;

    H = CreateList();
    if (NULL == H)
    {
        printf("H is NULL\n");
        return;
    }
    

    InsertList(H, 10, 0);
    InsertList(H, 30, 0);
    InsertList(H, 10, 0);
    InsertList(H, 20, 0);
    InsertList(H, 10, 0);
    InsertList(H, 10, 0);

    printf("重复数据（元素）删除前\n");
    printf("==============================\n");
    ShowList(H);

    PurgeList(H);
    
    printf("==============================\n");
    printf("重复数据（元素）删除前\n");
    printf("==============================\n");

    ShowList(H);

    FreeList(H);
}