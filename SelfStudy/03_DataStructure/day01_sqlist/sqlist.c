#include "sqlist.h"

/************************************************
 * 函数名：CreateList
 * 功能：创建一个线性表
 * 参数：缺省
 * 返回值：
 *      成功返回创建的线性表L
 * 注意事项：无
 ************************************************/
sqlink CreateList()
{
    sqlink L;

    L = (sqlink)malloc(sizeof(sqlist)); //为线性表申请内存
                                        //malloc申请的空间在堆上
                                        //L接收malloc申请空间的首地址
                                        //sqlink进行强制类型转换
    /* 线性表创建失败 */
    if (L == NULL)
    {
        printf("list malloc failed\n"); //打印出错信息
        return L;                       //返回线性表L（孔表，未茶成功创建）
    }

    /* 线性表初始化 */
    memset(L, 0, sizeof(sqlist)); //清空线性表
    L->last = -1;                 //-1代表空值

    return L; //返回创建的线性表L
}

/************************************************
 * 函数名：ClearList
 * 功能：清空线性表
 * 参数：
 *      sqlink L:线性表
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ************************************************/
int ClearList(sqlink L)
{
    /* 判断传入的线性表L是否为空（合法） */
    if (L == NULL)
    {
        return -1;
    }

    memset(L, 0, sizeof(sqlist)); //清空线性表
    L->last = -1;                 //-1代表空值

    return 0;
}

/************************************************
 * 函数名：FreeList
 * 功能：删除线性表，释放对应空间
 * 参数：   
 *      sqlink L:线性表
 * 返回值：
 *      删除成功返回0
 *      删除失败返回-1
 * 注意事项：无
 ************************************************/
int FreeList(sqlink L)
{
    /* 判断传入的线性表L是否为空（合法） */
    if (L == NULL)
    {
        return -1;
    }

    free(L);  //释放线性表对应的空间
    L = NULL; //线性表置空
    
    return 0;
}

/************************************************
 * 函数名：EmptyList
 * 功能：判断线性表是否为空
 * 参数：   
 *      sqlink L:（要进行判断的）线性表
 * 返回值：
 *      线性表为空返回0
 *      线性表不为空返回1
 * 注意事项：无
 ************************************************/
int IsEmptyList(sqlink L)
{
    if (L->last == -1) //线性表为空
    {
        return 0;
    }
    else               //线性表不为空
    {
        return 1;
    }
}

/************************************************
 * 函数名：LengthOfList
 * 功能：获取线性表的长度
 * 参数：   
 *      sqlink L:线性表
 * 返回值：
 *      线性表为空返回0
 *      线性表不为空返回1
 * 注意事项：无
 ************************************************/
int LengthOfList(sqlink L)
{
    /* 判断传入的线性表L是否为空（合法） */
    if (L == NULL)
    {
        return -1;
    }

    return (L->last + 1); //返回线性表长度
}

/************************************************
 * 函数名：LocateList
 * 功能：定位指定数据在线性表中的位置
 * 参数：   
 *      sqlink L:线性表
 *      date_t value:要进行查找的数据
 * 返回值：
 *      定位成功返回相应的位置
 *      定位失败返回-1
 * 注意事项：无
 ************************************************/
int LocateList(sqlink L, data_t value)
{
    int i = 0; //辅助变量，用于循环遍历线性表数据

    /* 遍历线性表中的数据，查找是否与指定数据相同 */
    for (i = 0; i <= L->last; i++)
    {
        if (L->data[i] == value)
        {
            return i; //返回指定数据在线性表中的位置
        }
    }

    return -1;
}

/************************************************
 * 函数名：InsertList
 * 功能：往线性表中插入数据
 * 参数：   
 *      sqlink L:线性表
 *      data_t value:要插入的数据
 *      int pos:数据插入的位置
 * 返回值：
 *      插入成功返回0
 *      插入失败返回-1
 * 注意事项：无
 ************************************************/
int InsertList(sqlink L, data_t value, int pos)
{
    /* 元素插入首先判断线性表是否为满，（参数）插入位置是否合法 */

    int i = 0; //辅助变量

    /* 判断线性表是否为满（是否可继续插入数据） */
    if (L->last == N - 1)
    { 
        printf("List is full\n");
        return -1;
    }

    /* 判断（参数）插入位置是否合法 */
    if (pos  < 0 || pos > (L->last + 1))
    {
        printf("Pos is invalid\n");
        return -1;
    }

    /* 将要插入位置之后的元素依次向后移动 */
    for (i = L->last + 1; i >= pos; i--)
    {
        L->data[i+1] = L->data[i]; //将元素i依次移动到i+1的位置
    }

    /* 更新要插入位置的数据 */
    L->data[pos] = value;
    L->last++;

    return 0;
}

/************************************************
 * 函数名：ShowList
 * 功能：将线性表中的元素依次打印
 * 参数：   
 *      sqlink L:线性表
 *      data_t value:要插入的数据
 *      int pos:数据插入的位置
 * 返回值：
 *      打印成功返回0
 *      打印失败返回-1
 * 注意事项：无
 ************************************************/
int ShowList(sqlink L)
{
    int i = 0; //辅助变量

    /* 判断传入的线性表L是否为空（合法） */
    if (L == NULL)
    {
        return -1;
    }

/* 判断线性表是否为空表，不调用判断线性表是否为空的函数是因为函数一般为
     * 其他人员调用，且调用函数也是有开销的 */
    if (L->last == -1)
    {
        printf("List is empty\n");
    }

    /* 打印线性表中的元素 */
    for (i = 0; i <= L->last; i++)
    {
        printf("%d: %d\n", i, L->data[i]);
    }

    return 0;
}

/************************************************
 * 函数名：DeleteDataOfList
 * 功能：删除线性表中指定位置的数据
 * 参数：   
 *      sqlink L:线性表
 *      int pos:要删除数据的位置
 * 返回值：
 *      删除成功返回0
 *      删除失败返回-1
 * 注意事项：无
 ************************************************/
int DeleteDataOfList(sqlink L, int pos)
{
    int i = 0; //辅助变量

    /* 判断是否为空表 */
    if (L->last == -1)
    {
        printf("list is empty\n");
        return -1;
    }

    /* 判断要删除数据的位置是否合法 */
    if (pos < 0 || pos > L->last)
    {
        printf("delete pos is invalid\n");
        return -1;
    }

    /* 将要删除数据位置之后的数据依次前移 */
    for (i = pos + 1; i <= L->last; i++)
    {
        L->data[i-1] = L->data[i];
    }

    L->last--; //

    return 0;
}

/************************************************
 * 函数名：MergeList
 * 功能：合并两个线性表
 * 参数：   
 *      sqlink L1:线性表1
 *      sqlink L2:线性表2
 * 返回值：
 *      合并成功返回0
 *      合并失败返回-1
 * 注意事项：无
 ************************************************/
int MergeList(sqlink L1, sqlink L2)
{
    int i = 0;   //辅助变量
    int ret = 0; //接收查找数据后的返回值

    /* 遍历线性表L2中的数据 */
    while (i <= L2->last)
    {
        ret = LocateList(L1, L2->data[i]);
        /* 如果线性表L2中的数据不在线性表L1中，则将该数据插入L1中 */
        if (ret == -1)
        {
            /* 插入失败返回-1 */
            if (InsertList(L1, L2->data[i], L1->last + 1) == -1)
            {
                return -1;
            }
        }
        i++;
    }

    return 0;
}

/************************************************
 * 函数名：PurgeList
 * 功能：删除线性表中重复的数据
 * 参数：   
 *      sqlink L:线性表
 * 返回值：
 *      成功返回0
 * 注意事项：无
 ************************************************/
int PurgeList(sqlink L)
{
    /* 辅助变量，遍历用 */
    int i = 0;
    int j = 0;

    /* 只有一个数据直接返回 */
    if (L->last == 0)
    {
        return 0;
    }

    i = 1; //从第一个数据开始与之前的数据进行比较
    while (i <= L->last)
    {
        j = i - 1;
        /* 对0与i之间的数据进行遍历查看是否存在重复 */
        while (j >= 0)
        {
            if (L->data[i] == L->data[j])
            {
                DeleteDataOfList(L, i); //遇到重复的数据
                break;                  //当前遍历结束
            }
            else
            {
                j--; //数据前移
            }
        }

        if (j < 0)
        {
            i++;
        }
    }

    return 0;
}
