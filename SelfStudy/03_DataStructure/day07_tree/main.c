#include "linkqueue.h"
#include "tree.h"

int main(int argc, char const *argv[])
{
    bitree *r = NULL;

    /* 二叉树创建失败打印提示信息并退出 */
    if ((r = CreateTree()) == NULL)
    {
        printf("CreateTree failed\n");
        return -1;
    }

    printf("PreOrder:");
    PreOrder(r);
    puts("");

    printf("InOrder:");
    InOrder(r);
    puts("");

    printf("PostOrder:");
    PostOrder(r);
    puts("");

    printf("LayerOrder:");
    LayerOrder(r);
    
    return 0;
}
