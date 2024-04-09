#include "linklist.h"

/****************************************
 * 函数名：CreateList
 * 功能：创建一个链表
 * 参数：
 *      缺省
 * 返回值：
 *      成功返回创建的链表
 *      失败返回空表H
 * 注意事项：无
 ****************************************/
linklist CreateList()
{
    linklist H = NULL;

    H = (linklist)malloc(sizeof(listnode));
    if (NULL == H)
    {
        printf("malloc failed(create linklist)");
        return H;
    }

    /* 链表初始化（赋初值） */
    H->data = 0;
    H->pNext = NULL; //头节点pNext为空

    return H;
}

/****************************************
 * 函数名：InsertTailOfList
 * 功能：向链表尾部插入指定的数据
 * 参数：
 *      linklist H:要进行数据插入的链表
 *      data_t value:要插入的数据
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ****************************************/
int InsertOfListEnd(linklist H, data_t value)
{
    linklist p;
    linklist q;

    if (NULL == H)
    {
        printf("H is NULL\n");
        return -1;
    }

    p = (linklist)malloc(sizeof(listnode));
    if (NULL == p)
    {
        perror("malloc failed");
        return -1;
    }

    q = (linklist)malloc(sizeof(listnode));
    if (NULL == q)
    {
        perror("malloc failed");
        return -1;
    }

    p->data = value;
    p->pNext = NULL; //尾部插入，尾节点pNext为空

    q = H;
    /* 遍历H，直到找到尾节点 */
    while (q->pNext != NULL)
    {
        q = q->pNext;
    }

    q->pNext = p; //在链表尾部插入新的节点

    return 0;
}

/****************************************
 * 函数名：GetList
 * 功能：按照链表序号查找对应节点
 * 参数：
 *      linklist H:要进行查找的链表
 *      int pos:要查找的序号
 * 返回值：
 *      成功返回查找位置的地址
 *      失败返回NULL
 * 注意事项：无
 ****************************************/
linklist GetList(linklist H, int pos)
{
    int i = 0;
    linklist p = NULL;

    if (H == NULL)
    {
        printf("H is NULL(GetList)\n");
        return H;
    }

    /* 查找位置不合法返回链表H */
    if (-1 == pos)
    {
        return H;
    }

    if (pos < -1)
    {
        printf("pos is invalid(GetList)\n");
        return NULL;
    }

    p = H;
    i = -1;

    /* 循环pos + 1次 */
    while (i < pos)
    {
        p = p->pNext;

        if (NULL == p)
        {
            printf("Pos is invalid\n");
            return NULL;
        }

        i++;
    }

    return p;
}

/****************************************
 * 函数名：ShowList
 * 功能：打印链表中的数据
 * 参数：
 *      linklist H:要进行数据插入的链表
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ****************************************/
int ShowList(linklist H)
{
    linklist p = NULL;

    if (NULL == H)
    {
        printf("H is NULL\n");
        return -1;
    }

    p = H;

    while (p->pNext != NULL)
    {
        printf("%d ", p->pNext->data);
        p = p->pNext;
    }

    puts("");

    return 0;
}

/****************************************
 * 函数名：InsertList
 * 功能：向链表中指定位置插入数据
 * 参数：
 *      linklist H:要进行数据插入的链表
 *      data_t value:要插入的数据
 *      int pos:要插入的位置
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ****************************************/
int InsertList(linklist H, data_t value, int pos)
{
    linklist p = NULL;
    linklist q = NULL;
    
    if (NULL == H)
    {
        printf("H is NULL\n");
        return -1;
    }

    p = GetList(H, pos - 1);
    if (NULL == p)
    {
        printf("GetList failed\n");
        return -1;
    }

    q = (linklist)malloc(sizeof(listnode));
    if (NULL == q)
    {
        printf("malloc failed\n");
        return -1;
    }

    /* 新节点初始化 */
    q->data = value;
    q->pNext = NULL;

    /* 插入新节点 */
    q->pNext = p->pNext;
    p->pNext = q;

    return 0;
}

/****************************************
 * 函数名：DeleteList
 * 功能：删除链表中指定位置的节点（数据）
 * 参数：
 *      list H:要进行数据删除的链表
 *      int pos:要删除的位置
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ****************************************/
int DeleteList(linklist H, int pos)
{
    linklist q = NULL;
    linklist p = NULL;

    if (NULL == H)
    {
        printf("H is NULL\n");
        return -1;
    }

    p = GetList(H, pos - 1);
    if (NULL == p)
    {
        printf("GetList failed\n");
        return -1;
    }

    if (NULL == p->pNext)
    {
        printf("Delete pos is invalid\n");
        return -1;
    }

    q = p->pNext;
    p->pNext = q->pNext; //等价于p->pNext = p->pNext->pNext;

    /* 释放空间 */
    printf("free: %d\n", q->data);
    free(q);
    q = NULL;
    
    return 0;
}

/****************************************
 * 函数名：FreeList
 * 功能：删除链表申请的内存空间
 * 参数：
 *      list H:要进行数据删除的链表
 * 返回值：
 *      成功返回NULL
 *      失败返回NULL，并打印错误信息
 * 注意事项：无
 ****************************************/
linklist FreeList(linklist H)
{
    linklist p = NULL;

    if (NULL == H)
    {
        printf("H is NULL\n");
        return NULL;
    }

    p = H;
    printf("free:");

    while (H != NULL)
    {
        p = H;
        printf("%d ", p->data);
        H = H->pNext; //p和H指向同一个节点，不能释放完再去访问
                      //这里需要把H = H->pNext放在free(p)前面

        free(p);
    }

    puts("");

    return NULL;
}

