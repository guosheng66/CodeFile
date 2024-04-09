#include "sqlist.h"

/************************************************
 * 函数名：CreateList
 * 功能：创建一个线性表
 * 参数：缺省
 * 返回值：
 *      成功返回创建的线性表L
 *      失败返回空
 * 注意事项：无
 ************************************************/
sqlink CreateList()
{
    sqlink L;

    /*为线性表申请空间，malloc申请的空间在堆上
      L接收malloc申请空间的首地址  
      sqlink进行强制类型转换 */
    L = (sqlink)malloc(sizeof(sqlist));
    if (NULL == L)
    {
        perror("failed to malloc(create list)");
        return NULL;
    }

    /* 线性表初始化 */
    memset(L, 0, sizeof(sqlink));
    L->last = -1; //-1代表空值，已到线性表末尾

    return L;
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
    if (NULL == L)
    {
        return -1;
    }

    /* 清空线性表 */
    memset(L, 0, sizeof(sqlist));
    L->last = -1;

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
    if (NULL == L)
    {
        return -1;
    }

    free(L);
    L = NULL; //将线性表L置空

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
int EmptyList(sqlink L)
{
    if (NULL == L)
    {
        return -1;
    }

    if (-1 == L->last)
    {
        return 0;
    }
    else
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
 *      成功返回线性表的长度
 *      失败返回-1
 * 注意事项：无
 ************************************************/
int LenOfList(sqlink L)
{
    if (NULL == L)
    {
        return -1;
    }

    return (L->last + 1); //线性表长度
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
    int i = 0;

    if (NULL == L)
    {
        return -1;
    }

    for (i = 0; i <= L->last; i++)
    {
        if (L->data[i] == value)
        {
            return i;
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
    int i = 0;

    if (L->last == MAXLEN - 1)
    {
        printf("List is full\n");
        return -1;
    }

    /* 判断（参数）插入位置是否合法 */
    if (pos < 0 || pos > (L->last + 1) || pos >= MAXLEN)
    {
        printf("Pos is invalid\n");
        return -1;
    }

    /* 将要插入位置之后的元素依次向后移动 */
    for (i = L->last + 1; i >= pos; i--)
    {
        L->data[i+1] = L->data[i];
    }

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
    int i = 0;

    if (NULL == L)
    {
        return -1;
    }

    /* 判断线性表是否为空表，不调EmptyList()函数判断是因为
       函数一般为其他人员调用使用，在程序内调用函数是有开销的 */
    if (-1 == L->last)
    {
        printf("List is empty\n");
        return -1;
    }

    /* 打印表中的元素 */
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
    int i = 0;

    if (-1 == L->last)
    {
        printf("list is empty\n");
        return -1;
    }

    if (pos < 0 || pos > L->last || pos >= MAXLEN)
    {
        printf("Delete pos is invalid\n");
        return -1;
    }

    for (i = pos + 1; i <= L->last; i++)
    {
        L->data[i - 1] = L->data[i];
    }

    L->last--;

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
    int i = 0;
    int ret = 0;

    if (NULL == L1 || NULL == L2)
    {
        printf("L1 || L2 is empty\n");
        return -1;
    }

    while (i <= L2->last)
    {
        ret = LocateList(L1, L2->data[i]);
        if (-1 == ret)
        {
            if (-1 == InsertList(L1, L2->data[i], L1->last + 1))
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
 *      失败返回-1
 * 注意事项：无
 ************************************************/
int PurgeList(sqlink L)
{
    int i = 0;
    int j = 0;

    if (NULL == L)
    {
        printf("L is NULL\n");
        return -1;
    }

    if (0 == L->last)
    {
        return 0;
    }

    i = 1;
    while (i <= L->last)
    {
        j = i - 1;

        while (j >= 0)
        {
            if (L->data[i] == L->data[j])
            {
                DeleteDataOfList(L, i);
                break;
            }
            else
            {
                j--;
            }
        }

        if (j < 0)
        {
            i++;
        }
    }

    return 0;
}