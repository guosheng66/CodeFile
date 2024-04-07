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
    linklist H = NULL; //创建一个链表变量

    H = (linklist)malloc(sizeof(listnode)); //为链表创建申请空间
                                            //强制类型转换，因为malloc返回的是void *类型的指针
    /* 链表内存申请失败打印失败信息并返回H */
    if (H == NULL)
    {
        printf("malloc failed\n");
        return H; //此时的链表H未成功申请空间
    }

    /* 链表初始化（赋初值） */
    H->data = 0;     
    H->pNext = NULL; //头节点pNext为空

    return H; //返回成功创建的链表H
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
int InsertTailOfList(linklist H, data_t value)
{
    linklist p; //建立一个新节点存放要插入的数据
    linklist q; //建立节点找到当前链表的尾节点

    /* 如果链表为空打印提示信息并退出 */
    if (H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    }

    /* 新节点申请空间失败打印出错信息并退出 */
    if ((p = (linklist)malloc(sizeof(listnode))) == NULL)
    {
        printf("malloc failed\n");
        return -1;
    }
    
    /* 新节点出出初始化（赋值） */
    p->data = value;
    p->pNext = NULL; //尾部插入，尾节点pNext为空

    q = H; //从头开始遍历
    /* 当q->pNext不为空的时候一直向后遍历，直到找到尾节点 */
    while (q->pNext != NULL)
    {
        q = q->pNext;
    }

    q->pNext = p; //在尾部插入新的节点

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
    linklist p = NULL; //建立新节点（指针）用于遍历
    int i = 0;         //辅助变量，循环使用

    /* 如果链表为空（无效）打印提示信息并退出 */
    if (H == NULL)
    {
        printf("H is NULL\n");
        return H;
    }

    /* 查找位置不合法返回链表H */
    if (pos == -1)
    {
        return H;
    }

    /* 位置无效打印提示信息并返回NULL */
    if (pos < -1)
    {
        printf("pos is invalid\n");
        return NULL;
    }

    p = H;
    i = -1;
    /* 循环pos+1次 */
    while (i < pos)
    {
        p = p->pNext;
        /* pos数值太大超出链表范围，跳出循环 */
        if (p == NULL)
        {
            printf("pos is invalid\n");
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
    linklist p = NULL; //定义变量用于遍历链表

    /* 如果链表为空（无效）打印提示信息并退出 */
    if (H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    }

    p = H;
    /* 遍历链表依次打印，指导尾部节点数据打印完成 */
    while (p->pNext != NULL)
    {
        printf("%d ", p->pNext->data);
        p = p->pNext;
    }
    puts(""); //打印换行符

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
    linklist p = NULL; //创建新节点获取要插入位置前驱的节点地址
    linklist q = NULL; //创建新节点存储要插入的数据
    
    /* 如果链表为空（无效）打印提示信息并退出 */
    if (H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    }

    p = GetList(H, pos - 1);  //获取插入位置节点前驱的地址赋给p
    /* 节点前驱地址获取失败打印提示信息并退出 */
    if (p == NULL)
    {
        printf("GetList failed\n");
        return -1;
    }

    /* 为新的节点p申请空间 */
    if ((q = (linklist)malloc(sizeof(listnode))) == NULL)
    {
        printf("malloc failed\n"); //空间申请失败打印提示信息
        return -1;
    }

    /* 新节点初始化（赋值） */
    q->data = value;
    q->pNext = NULL;

    /* 在原有链表中插入新的节点 */
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
    linklist p = NULL; //创建新节点获取要位置的节点地址
    linklist q = NULL; //创建新节点要删除位置的节点

    /* 如果链表为空（无效）打印提示信息并退出 */
    if (H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    }

    p = GetList(H, pos - 1); //获取删除位置节点前驱的地址赋给p
    /* 节点前驱地址获取失败打印提示信息并退出 */
    if (p == NULL)
    {
        return -1;
    }

    /* 删除位置无效打印提示信息并退出 */
    if (p->pNext == NULL)
    {
        printf("delete pos is invalid\n");
        return -1;
    }

    q = p->pNext;
    p->pNext = q->pNext; //等价于：p->pNext = p->pNext->pNext;

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
 * 注意事项：无
 ****************************************/
linklist FreeList(linklist H)
{
    linklist p = NULL; //创建新节点，用于遍历链表

    /* 如果链表为空（无效）打印提示信息并退出 */
    if (H == NULL)
    {
        printf("H is NULL\n");
        return NULL;
    }

    p = H;
    printf("free:");
    /* 当H不为空，及链表尾节点未释放依次对节点空间进行释放 */
    while (H != NULL)
    {
        p = H;
        printf("%d ", p->data);
        H = H->pNext; //p和H指向同一个节点，不能释放完在去访问
                      //这里需要把H = H->pNext放到free(p)之前
        free(p);
    }

    puts(""); //打印换行符
    
    return NULL;
}
