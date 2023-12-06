#include "linkqueue.h"
#include "tree.h"

/********************************************
 * 函数名称：CrteateTree
 * 功能：创建树形结构
 * 参数：
 *      缺省
 * 返回值：
 *      成功返回二叉树r
 *      失败返回NULL
 * 注意事项：无
 ********************************************/
bitree *CreateTree()
{
    data_t ch;        //定义变量接收用户输入的字符
    bitree *r = NULL; //定义树r

    scanf("%c", &ch); 
    /* 用户输入#，则为空树，返回即可 */
    if (ch == '#')
    {
        return NULL;
    }

    /* 节点空间申请失败打印提示信息并退出 */
    if ((r = (bitree *)malloc(sizeof(bitree))) == NULL)
    {
        printf("malloc failed\n");
        return NULL;
    }

    /* 封装节点（树结构的创建使用递归调用的方法） */
    r->data = ch;
    r->left = CreateTree();
    r->right = CreateTree();

    return r;
}

/********************************************
 * 函数名称：PreOrder
 * 功能：先序遍历
 * 参数：
 *      bitree *r:二叉树
 * 返回值：
 *      缺省
 * 注意事项：无
 ********************************************/
void PreOrder(bitree *r)
{
    /* 递归函数出口，二叉树为空直接返回 */
    if (r == NULL)
    {
        return;
    }

    printf("%c", r->data); //访问二叉树的根
    PreOrder(r->left);     //访问左子树
    PreOrder(r->right);    //访问右子树
}

/********************************************
 * 函数名称：InOrder
 * 功能：中序遍历
 * 参数：
 *      bitree *r:二叉树
 * 返回值：
 *      缺省
 * 注意事项：无
 ********************************************/
void InOrder(bitree *r)
{
    /* 递归函数出口，二叉树为空直接返回 */
    if (r == NULL)
    {
        return;
    }

    InOrder(r->left);      //访问左子树
    printf("%c", r->data); //访问二叉树的根
    InOrder(r->right);     //访问右子树
}

/********************************************
 * 函数名称：PostOrder
 * 功能：后序遍历
 * 参数：
 *      bitree *r:二叉树
 * 返回值：
 *      缺省
 * 注意事项：无
 ********************************************/
void PostOrder(bitree *r)
{
    /* 递归函数出口，二叉树为空直接返回 */
    if (r == NULL)
    {
        return;
    }

    PostOrder(r->left);    //访问左子树
    PostOrder(r->right);   //访问右子树
    printf("%c", r->data); //访问二叉树的根
}

/********************************************
 * 函数名称：LayerOrder
 * 功能：层次遍历
 * 参数：
 *      bitree *r:二叉树
 * 返回值：
 *      缺省
 * 注意事项：无
 ********************************************/
void LayerOrder(bitree *r)
{
    linkqueue *lq = NULL;

    /* 队列创建失败直接返回 */
    if ((lq = CreateQueue()) == NULL)
    {
        return;
    }

    /* 如果二叉树为空直接返回 */
    if (r == NULL)
    {
        return;
    }

    printf("%c", r->data);
    EnQueue(lq, r);        //将接单数据元素入队

    /* 当队列不为空的时候执行入队循环 */
    while (!EmptyQueue(lq))
    {
        r = DeQueue(lq);
        if (r->left)
        {
            printf("%c", r->left->data);
            EnQueue(lq, r->left);
        }

        if (r->right)
        {
            printf("%c", r->right->data);
            EnQueue(lq, r->right);
        }
    }

    puts("");
}