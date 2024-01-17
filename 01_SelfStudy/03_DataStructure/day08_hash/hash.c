#include "hash.h"

/**************************************
 * 函数名：CreateHash
 * 功能：创建哈希表
 * 参数：
 *      缺省
 * 返回值：
 *      成功返回创建的哈希表HT
 *      失败返回NULL
 * 注意事项：无
 **************************************/
hash *CreateHash()
{
    hash *HT = NULL; //定义一个哈希表

    /* 给哈希表申请空间 */
    if ((HT = (hash*)malloc(sizeof(hash))) == NULL)
    {
        printf("malloc failed\n");
        return NULL;
    }

    memset(HT, 0, sizeof(hash)); //哈希表初始化，数据元素置-1

    return HT;
}

/**************************************
 * 函数名：InsertHash
 * 功能：往哈希表中插入数据
 * 参数：
 *      hash *HT:哈希表
 *      datatype key:要插入的数据
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 **************************************/
int InsertHash(hash *HT, datatype key)
{
    linklist p = NULL; //创建结点指针
    linklist q = NULL; //创建结点指针

    /* 哈希表为空打印提示信息并退出 */
    if (HT == NULL)
    {
        printf("HT is NULL");
        return -1;
    }

    /* 申请空间 */
    if ((p = (linklist)malloc(sizeof(listnode))) == NULL)
    {
        printf("malloc failed\n");
        return -1;
    }

    /* 封装结点 */
    p->key = key;
    p->value = key % N;
    p->next = NULL;

    q = &(HT->data[key % N]); //找到结点q在表中的地址

    /* 表中有值执行循环 */
    while (q->next && q->next->key < p->key)
    {
        q = q->next;
    }

    /* 将结点p放在结点q后面 */
    p->next = q->next;
    q->next = p;

    return 0;
}

/**************************************
 * 函数名：SearchHash
 * 功能：在哈希表中查找数据
 * 参数：
 *      hash *HT:哈希表HT
 *      datatype key:要查找的数据
 * 返回值：
 *      成功返回要查找的数据所在的位置
 *      失败返回NULL
 * 注意事项：无
 **************************************/
linklist SearchHash(hash *HT, datatype key)
{
    linklist p = NULL; //创建结点指针

    /* 哈希表为空打印提示信息并退出 */
    if (HT == NULL)
    {
        printf("HT is NULL\n");
        return NULL;
    }

    p = &(HT->data[key%N]); //找到数据在哈希表中可能的位置

    /* 遍历查找key的位置 */
    while (p->next && p->next->key != key)
    {
        p = p->next;
    }

    if (p->next == NULL)
    {
        return NULL;
    }
    else
    {
        printf("found\n");
        return p->next;
    }    
}