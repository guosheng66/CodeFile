#include "hash.h"

/**************************************
 * 函数名：CreateHash
 * 功能：创建哈希表
 * 参数：
 *      缺省
 * 返回值：
 *      成功返回创建的哈希表ht
 *      失败返回NULL
 * 注意事项：无
 **************************************/
hash *CreateHash()
{
    hash *ht = NULL;

    ht = (hash *)malloc(sizeof(hash));
    if (NULL == ht)
    {
        printf("malloc failed\n");
        return NULL;
    }

    memset(ht, 0, sizeof(hash));

    return ht;
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
int InsertHash(hash *ht, datatype key)
{
    linklist p = NULL;
    linklist q = NULL;

    if (NULL == ht)
    {
        printf("ht is NULL(in InsertHash)\n");
        return -1;
    }

    p = (linklist)malloc(sizeof(listnode));
    if (NULL == p)
    {
        perror("malloc failed\n");
        return -1;
    }

    p->key = key;
    p->value = key % N;
    p->next = NULL;

    q = &(ht->data[key % N]); //找到节点q在表中的地址

    /* 表中有值执行循环 */
    while (q->next && q->next->key < p->key)
    {
        q = q->next;
    }

    /* 将节点p放在q后面 */
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
linklist SearchHash(hash *ht, datatype key)
{
    linklist p = NULL;

    if (NULL == ht)
    {
        printf("ht is NULL(in SearchHash)\n");
        return NULL;
    }

    p = &(ht->data[key % N]);

    /* 遍历查找key的位置 */
    while (p->next && p->next->key != key)
    {
        p = p->next;
    }

    if (NULL == p->next)
    {
        return NULL;
    }
    else
    {
        printf("found\n");

        return p->next;
    }
}
