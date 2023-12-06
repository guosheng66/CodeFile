#include "linklist.h"

void InsertTailTest();
void InsertTest();
void DeleteTest();
void FreeTest();
void ReverseTest();
void MaxSumTest();
void MergeTest();

int main(int argc, char const *argv[])
{
    // InsertTailTest();
    // InsertTest();
    // DeleteTest();
    // FreeTest();
    // ReverseTest();
    // MaxSumTest();
    MergeTest();

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
    int value = 0;     //接收用户输入的数据
    linklist H = NULL;
    linklist p = NULL;

    H = CreateList();
    /* 链表创建失败退出 */
    if (H == NULL)
    {
        printf("CreateList failed\n");
        return;
    }

    while (1)
    {
        printf("input:"); //提示用户输入数据
        scanf("%d", &value);
        /* 当用户输入-1时跳出循环 */
        if (value == -1)
        {
            break;
        }

        InsertTailOfList(H, value); //将用户输入的数据插入在链表的尾部
    }

    ShowList(H); //打印链表的数据信息

    p = GetList(H, 6);               //查找处于链表第一个位置的节点
    /* 判断节点是否存在 */
    if (p != NULL)
    {
        printf("value = %d\n", p->data); //打印第一个节点的数据
    }

}

/*********************************************
 * 函数名：InsertTest
 * 功能：链表指定位置数据插入测试
 * 参数：缺省
 * 返回值：无
 * 注意事项：无
 *********************************************/
void InsertTest()
{
    linklist H = NULL;

    H = CreateList();
    /* 链表创建失败打印提示信息并退出 */
    if (H == NULL)
    {
        printf("fail to create list\n");
        return;
    }

    /* 向链表中指定位置插入数据 */
    InsertList(H, 10, 0);
    InsertList(H, 20, 1);
    InsertList(H, 30, 2);
    InsertList(H, 40, 3);
    InsertList(H, 50, 4);
    InsertList(H, 60, 5);

    printf("数据插入前的链表：");
    ShowList(H); //打印链表的数据信息

    /* 向链表中指定位置插入数据 */
    InsertList(H, 80, 2);
    InsertList(H, 100, 4);

    printf("数据插入后的链表：");
    ShowList(H); //打印链表的数据信息
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
    /* 链表创建失败打印提示信息并退出 */
    if (H == NULL)
    {
        printf("fail to create list\n");
        return;
    }

    /* 向链表中指定位置插入数据 */
    InsertList(H, 10, 0);
    InsertList(H, 20, 1);
    InsertList(H, 30, 2);
    InsertList(H, 40, 3);
    InsertList(H, 50, 4);
    InsertList(H, 60, 5);

    printf("数据删除前的链表：");
    ShowList(H); //打印链表的数据信息

    /* 向链表中指定位置插入数据 */
    DeleteList(H, 2);

    printf("第二个位置数据删除后的链表：\n");
    ShowList(H); //打印链表的数据信息

    DeleteList(H, 4); //注意该次删除操作
                      //每次删除操作后链表是会发生变化的
                      //所以删除位置pos都是针对当前链表而言的

    printf("第四个位置数据删除后的链表：\n");
    ShowList(H); //打印链表的数据信息
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
    /* 链表创建失败打印提示信息并退出 */
    if (H == NULL)
    {
        printf("fail to create list\n");
        return;
    }

    /* 向链表中指定位置插入数据 */
    InsertList(H, 10, 0);
    InsertList(H, 20, 1);
    InsertList(H, 30, 2);
    InsertList(H, 40, 3);
    InsertList(H, 50, 4);
    InsertList(H, 60, 5);

    printf("Free前的链表：\n");
    printf("H: %p\n", H);
    ShowList(H); //打印链表的数据信息
    
    /* 此处非常重要，多加理解 */
    H = FreeList(H); //释放链表空间
                     //H是一个形参，要么用二级指针传递H的地址，或者用H接收返回值
                     //否则H不会改变

    printf("Free后的链表：\n");
    printf("H: %p\n", H);
    ShowList(H); //打印链表的数据信息
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
    /* 链表创建失败打印提示信息并退出 */
    if (H == NULL)
    {
        printf("fail to create list\n");
        return;
    }

    /* 向链表中指定位置插入数据 */
    InsertList(H, 10, 0);
    InsertList(H, 20, 1);
    InsertList(H, 30, 2);
    InsertList(H, 40, 3);
    InsertList(H, 50, 4);
    InsertList(H, 60, 5);

    printf("反转前的链表：\n");
    ShowList(H);    //打印链表的数据信息
    
    ReverseList(H); //反转链表H

    printf("反转后的链表：\n");
    ShowList(H);    //打印链表的数据信息
}

/*********************************************
 * 函数名：SumTest
 * 功能：求链表相邻节点和的最大值
 * 参数：缺省
 * 返回值：无
 * 注意事项：无
 *********************************************/
void MaxSumTest()
{
    linklist H = NULL;
    linklist r = NULL; //创建新节点指向和最大相邻节点的前节点
    data_t sum = 0;    //定义变量存储两个节点的和

    H = CreateList();
    /* 链表创建失败打印提示信息并退出 */
    if (H == NULL)
    {
        printf("fail to create list\n");
        return;
    }

    /* 向链表中指定位置插入数据 */
    InsertList(H, 10, 0);
    InsertList(H, 20, 1);
    InsertList(H, 30, 2);
    InsertList(H, 40, 3);
    InsertList(H, 50, 4);
    InsertList(H, 60, 5);

    ShowList(H);
    r = MaxOfAdjNodes(H, &sum);
    printf("Max: %d\n", sum);

    ShowList(H);
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
    linklist H1 = NULL;
    linklist H2 = NULL;

    H1 = CreateList();
    /* 链表创建失败打印提示信息并退出 */
    if (H1 == NULL)
    {
        printf("fail to create list\n");
        return;
    }

    H2 = CreateList();
    /* 链表创建失败打印提示信息并退出 */
    if (H2 == NULL)
    {
        printf("fail to create list\n");
        return;
    }

    /* 向链表H1中指定位置插入数据 */
    InsertList(H1, 10, 0);
    InsertList(H1, 20, 1);
    InsertList(H1, 30, 2);
    InsertList(H1, 40, 3);
    InsertList(H1, 50, 4);
    InsertList(H1, 60, 5);

    /* 向链表H2中指定位置插入数据 */
    InsertList(H2, 40, 0);
    InsertList(H2, 50, 1);
    InsertList(H2, 60, 2);
    InsertList(H2, 70, 3);
    InsertList(H2, 80, 4);
    InsertList(H2, 90, 5);

    ShowList(H1);
    ShowList(H2);

    MergeList(H1, H2);
    printf("Merge:");
    ShowList(H1);

    FreeList(H1);
    FreeList(H2); //H2中其余节点已经合并到新的链表中了，只剩下头节点
}