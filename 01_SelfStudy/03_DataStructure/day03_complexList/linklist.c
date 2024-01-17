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

/****************************************
 * 函数名：ReverseList
 * 功能：链表的倒置（头插法）
 * 参数：
 *      list H:要进行倒置的链表
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ****************************************/
int ReverseList(linklist H)
{
    linklist p = NULL; //创建新节点，一直指向待操作的点
    linklist q = NULL; //辅助完成插入

    /* 如果链表为空（无效）打印提示信息并退出 */
    if (H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    }
    
    /* 如果链表为空或者链表H只有一个节点则退出（是否反转链表无变化 ） */
    if (H->pNext == NULL || H->pNext->pNext == NULL)
    {
        return 0;
    }

    p = H->pNext->pNext;    //P指向链表的第二个节点，防止后续置空后其余节点丢失
    H->pNext->pNext = NULL; //链表的第二个节点指针置空

    while (p != NULL)
    {
        q = p;        //此处不能用节点p直接进行后续操作，使用节点q辅助完成后续操作
        p = p->pNext; //指向下一个需要操作的节点
 
        /* 将节点q移动到节点H后面，此处移动顺序需要注意*/
        q->pNext = H->pNext;
        H->pNext = q;
    }

    return 0;
}

/****************************************
 * 函数名：MaxOfAdjNodes
 * 功能：求链表相邻两个节点和的最大值
 * 参数：
 *      list H:链表H
 *      data_t *value:最大值的地址
 * 返回值：
 *      成功返回和最大相邻节点的前节点指针
 *      失败返回NULL
 * 注意事项：无
 ****************************************/
linklist MaxOfAdjNodes(linklist H, data_t *value)
{
    linklist p = NULL; //创建新节点指向要求和的相邻节点的前节点
    linklist q = NULL; //创建新节点指向要求和的相邻节点的后节点
    linklist r = NULL; //创建新节点指向和最大相邻节点的前节点
    data_t sum = 0;    //定义变量存储两个节点的和

    /* 如果链表为空（无效）打印提示信息并退出 */
    if (H == NULL)
    {
        printf("H is NULL\n");
        return NULL;
    }

    /* 如果链表节点数小于等于二则打印提示信息并返回H */
    if (H->pNext == NULL || H->pNext->pNext == NULL || H->pNext->pNext->pNext == NULL)
    {
        printf("The number of nodes is less than Three\n");
        return H;
    }

    p = H->pNext;        //待求和的前节点
    q = H->pNext->pNext; //待求和的后节点(~ q = p->PNext;)
    
    /* 初始化默认第一第二节点和为最大值 */
    r = p;                   //将前节点赋值给r
    sum = p->data + q->data; //对第一个和第二个节点进行求和

    /* 对链表进行遍历，指导末尾 */
    while (q->pNext != NULL)
    {
        q = q->pNext;
        p = p->pNext;
        if (sum < p->data + p->data)
        {
            sum = p->data + q->data;
            r = p;
        }    
    }   

    *value = sum;

    return r;
}

/****************************************
 * 函数名：MergeList
 * 功能：合并两个有序链表
 * 参数：
 *      list H1:链表H1
 *      list H2:链表H2
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ****************************************/
int MergeList(linklist H1, linklist H2)
{
    linklist p = NULL; //创建新节点用于操作链表H1
    linklist q = NULL; //创建新节点用于操作链表H2
    linklist r = NULL; //创建新节点用于操作链表H1

    /* 如果链表为空（无效）打印提示信息并退出 */
    if (H1 == NULL || H2 == NULL)
    {
        printf("List is NULL\n");
        return -1;
    }

    p = H1->pNext;
    q = H2->pNext;    
    r = H1;            //将H1赋给r作为完成合并操作后存储节点的新链表
    H1->pNext == NULL; //头节点赋空值
    H2->pNext == NULL; //头节点赋空值

    /* 当p和q不为空的时候循环执行 */
    while (p && q)
    {
        if (p->data <= q->data)
        {
            r->pNext = p;
            p = p->pNext;
            r = r->pNext;
            r ->pNext = NULL;
        } 
        else
        {
            r->pNext = q;
            q = q->pNext;
            r = r->pNext;
            r->pNext = NULL;
        }
    }

    /* 如果其中一个链表已经遍历完成，另一个未完成，则直接将剩余节点拼接到新的链表即可 */
    if (p == NULL)
    {
        r->pNext = q;
    }
    else
    {
        r->pNext = p;
    }

    return 0;
}