#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *base = NULL;
    int i = 0;

    if (2 > argc)
    {
        printf("argc error");
        return -1;
    }

    /* 使用calloc申请内存 */
    base = (int *)calloc(argc - 1, sizeof(int));
    if (NULL == base)
    {
        printf("calloc error\n");
        return -1;
    }

    /* 将字符串转为int型数据存放在base指向的内存中 */
    for (i = 0; i < argc - 1; i++)
    {
        base[i] = atoi(argv[i + 1]);
    }

    /* 打印base数组中的数据 */
    printf("输入的数据为：\n");
    for (i = 0; i < argc; i++)
    {
        printf("%d", base[i]);
    }
    putchar('\n');

    free(base);
    
    return 0;
}
