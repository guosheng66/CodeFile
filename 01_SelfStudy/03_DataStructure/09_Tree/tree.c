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
    data_t ch;
    bitree *r = NULL; 

    scanf("%c", &ch);

    if ('#' == ch)
    {
        return NULL;
    }

    r = (bitree *)malloc(sizeof(bitree));
    if (NULL == r)
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
    if (NULL == r)
    {
        return;
    }

    printf("%c", r->data);
    PreOrder(r->left);
    PreOrder(r->right);
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
    if (NULL == r)
    {
        return;
    }

    InOrder(r->left);
    printf("%c", r->data);
    InOrder(r->right);
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

    lq = CreateQueue();
    if (NULL == lq)
    {
        return;
    }    

    if (NULL == r)
    {
        return;
    }

    printf("%c", r->data);
    EnQueue(lq, r);

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