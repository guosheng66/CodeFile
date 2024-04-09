#include "sqlist.h"

int main(int argc, char const *argv[])
{
    // InsertTest();
    // DeleteTest();
    MergeTest();

    return 0;
}


/************************************************
 * 函数名：InsertTest
 * 功能：线性表插入测试
 * 参数：
 *      缺省
 * 返回值：无
 * 注意事项：无
 ************************************************/
void InsertTest()
{
    sqlink L;

    L = CreateList();
    if (NULL == L)
    {
        return;
    }

    printf("数据插入前的线性表：\n");
    printf("=====================================\n");
    ShowList(L);

    /* 注意插入位置和元素在线性表中实际所处的位置之间的关系 */
    InsertList(L, 10, 0);
    InsertList(L, 20, 0);
    InsertList(L, 30, 0);
    InsertList(L, 40, 0);
    InsertList(L, 50, 0);
    InsertList(L, 60, 0);

    printf("len of list: %d\n", LenOfList(L));
    printf("=====================================\n");
    printf("数据插入后的线性表：\n");
    printf("=====================================\n");
    ShowList(L);

    FreeList(L);
}

/************************************************
 * 函数名：DeleteTest
 * 功能：线性表重复数据删除测试
 * 参数：
 *      缺省
 * 返回值：无
 * 注意事项：无
 ************************************************/
void DeleteTest()
{
    sqlink L = NULL;

    L = CreateList();
    if (NULL == L)
    {
        return;
    }

    printf("数据插入前的线性表\n");
    printf("=====================================\n");
    ShowList(L);


    InsertList(L, 10, 0);
    InsertList(L, 20, 0);
    InsertList(L, 30, 0);
    InsertList(L, 40, 0);
    InsertList(L, 50, 0);
    InsertList(L, 10, 0);
    InsertList(L, 10, 0);
    InsertList(L, 20, 0);
    printf("=====================================\n");
    printf("数据插入后的线性表\n");
    printf("=====================================\n");
    ShowList(L);

    printf("=====================================\n");
    printf("删除指定位置元素后的线性表\n");
    printf("=====================================\n");
    DeleteDataOfList(L, 2);
    ShowList(L);

    printf("=====================================\n");
    printf("删除重复元素后的线性表\n");
    printf("=====================================\n");
    PurgeList(L);
    ShowList(L);

    FreeList(L);
}

/************************************************
 * 函数名：MergeTest
 * 功能：合并两个线性表中不重复的数据
 * 参数：
 *      缺省
 * 返回值：无
 * 注意事项：无
 ************************************************/
void MergeTest()
{
    sqlink L1;
    sqlink L2;

    L1 = CreateList(L1);
    if (NULL == L1)
    {
        printf("failed to create(list\n)");
        return;
    }

    L2 = CreateList(L2);
    if (NULL == L2)
    {
        printf("failed to create(list\n)");
        return;
    }

    printf("=====================================\n");
    printf("数据插入前的线性表\n");
    printf("=====================================\n");
    printf("L1\n");
    ShowList(L1);
    printf("L2\n");
    ShowList(L2);

    InsertList(L1, 10, 0);
    InsertList(L1, 20, 1);
    InsertList(L1, 30, 2);
    InsertList(L1, 40, 3);
    InsertList(L1, 50, 4);
    InsertList(L2, 60, 0);
    InsertList(L2, 70, 1);
    InsertList(L2, 80, 2);
    InsertList(L2, 90, 3);

    printf("=====================================\n");
    printf("数据插入后的线性表\n");
    printf("=====================================\n");
    printf("L1\n");
    ShowList(L1);
    printf("L2\n");
    ShowList(L2);

    printf("=====================================\n");
    printf("合并后的线性表\n");
    printf("=====================================\n");
    MergeList(L1, L2);
    printf("L1\n");
    ShowList(L1);
    printf("L2\n");
    ShowList(L2);

    FreeList(L1);
    FreeList(L2);
}