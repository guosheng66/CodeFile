#include "sqlist.h"

void InsertTest();
void DeleteTest();
void MergeTest();
void PurgeTest();

int main(int argc, char const *argv[])
{
    // InsertTest();
    // DeleteTest();
    // MergeTest();
    PurgeTest();

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
    int len = 0;      //定义变量接收线性表的长度
    sqlink L = NULL;  //定义一个线性表变量

    L = CreateList(); //创建一个线性表
    /* 线性表创建失败 */
    if (L == NULL)
    {
        return; //退出程序（函数为void类型，无返回值）
    }

    printf("数据插入前的线性表：\n");
    ShowList(L);           //打印线性表

    /* 注意此处插入顺序和元素实际所处的位置之间的关系 */
    InsertList(L, 10, 0);  //往线性表中插入数值
    InsertList(L, 20, 0);  //往线性表中插入数值
    InsertList(L, 30, 0);  //往线性表中插入数值
    InsertList(L, 40, 0);  //往线性表中插入数值
    
    len = LengthOfList(L); //查看线性表的长度
    printf("数据插入后的线性表：\n");
    ShowList(L);           //打印线性表

    // printf("len of sqlist: %d\n", len);

    FreeList(L);           //释放线性表的空间
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
    sqlink L = NULL;  //定义一个线性表变量

    L = CreateList(); //创建一个线性表
    /* 线性表创建失败 */
    if (L == NULL)
    {
        return; //退出程序（函数为void类型，无返回值）
    }

    printf("数据插入前的线性表：\n");
    ShowList(L);           //打印线性表
    
    /* 注意此处插入顺序和元素实际所处的位置之间的关系 */
    InsertList(L, 10, 0);  //往线性表中插入数值
    InsertList(L, 20, 1);  //往线性表中插入数值
    InsertList(L, 30, 2);  //往线性表中插入数值
    InsertList(L, 40, 3);  //往线性表中插入数值
    
    printf("数据插入后的线性表：\n");
    ShowList(L);           //打印线性表
    printf("指定位置数据删除后的线性表：\n");
    
    DeleteDataOfList(L, 2);//删除指定位置的数据
    ShowList(L);           //打印线性表

    FreeList(L);           //释放线性表的空间
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
    sqlink L1 = NULL;
    sqlink L2 = NULL;
    
    L1 = CreateList(); //创建一个线性表
    /* 线性表创建失败 */
    if (L1 == NULL)
    {
        return; //退出程序（函数为void类型，无返回值）
    }

    L2 = CreateList(); //创建一个线性表
    /* 线性表创建失败 */
    if (L2 == NULL)
    {
        return; //退出程序（函数为void类型，无返回值）
    }

    printf("数据插入前的线性表L1：\n");
    ShowList(L1);           //打印线性表
    printf("数据插入前的线性表L2：\n");
    ShowList(L2);           //打印线性表

    /* 注意此处插入顺序和元素实际所处的位置之间的关系 */
    InsertList(L1, 10, 0);  //往线性表中插入数值
    InsertList(L1, 20, 1);  //往线性表中插入数值
    InsertList(L1, 30, 2);  //往线性表中插入数值
    InsertList(L1, 40, 3);  //往线性表中插入数值
    InsertList(L2, 40, 0);  //往线性表中插入数值
    InsertList(L2, 50, 1);  //往线性表中插入数值
    InsertList(L2, 60, 2);  //往线性表中插入数值
    InsertList(L2, 70, 3);  //往线性表中插入数值

    printf("数据插入后的线性表L1：\n");
    ShowList(L1);           //打印线性表
    printf("数据插入后的线性表L2：\n");
    ShowList(L2);           //打印线性表

    MergeList(L1, L2);      //合并两个线性表
    printf("数据合并后的线性表L1：\n");
    ShowList(L1);           //打印线性表

    /* 释放线性表申请的空间 */
    FreeList(L1);
    FreeList(L2);
}

/************************************************
 * 函数名：PurgeTest
 * 功能：删除重复的数据
 * 参数：
 *      缺省
 * 返回值：无
 * 注意事项：无
 ************************************************/
void PurgeTest()
{
    sqlink L = NULL;  //定义一个线性表变量

    L = CreateList(); //创建一个线性表
    /* 线性表创建失败 */
    if (L == NULL)
    {
        return; //退出程序（函数为void类型，无返回值）
    }

    printf("数据插入前的线性表：\n");
    ShowList(L);           //打印线性表

    /* 注意此处插入顺序和元素实际所处的位置之间的关系 */
    InsertList(L, 10, 0);  //往线性表中插入数值
    InsertList(L, 10, 1);  //往线性表中插入数值
    InsertList(L, 20, 2);  //往线性表中插入数值
    InsertList(L, 30, 3);  //往线性表中插入数值
    InsertList(L, 40, 4);  //往线性表中插入数值
    InsertList(L, 30, 5);  //往线性表中插入数值
    InsertList(L, 40, 6);  //往线性表中插入数值
    
    printf("重复数据删除前的线性表：\n");
    ShowList(L);           //打印线性表

    PurgeList(L);          //删除线性表中的重复数据
    printf("重复数据删除后的线性表：\n");
    ShowList(L);           //打印线性表

    FreeList(L);           //释放线性表的空间
}


