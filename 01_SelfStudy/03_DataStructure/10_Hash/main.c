#include "hash.h"

int main(int argc, char const *argv[])
{
    hash *ht = NULL;
    int data[] = {23, 34, 14, 38, 46, 16, 68, 15, 7, 31, 26};
    int i = 0;
    int key = 0;
    linklist r = NULL;

    ht = CreateHash();
    if (NULL == ht)
    {
        printf("CreateHash failed\n");
        return -1;
    }

    for (i = 0; i < sizeof(data) / sizeof(int); i++)
    {
        InsertHash(ht, data[i]);
    }

    printf("input num:");
    scanf("%d", &key);

    r = SearchHash(ht, key);
    if (NULL == r)
    {
        printf("not found\n");
    }
    else
    {
        printf("found: %d %d\n", key, r->key); //打印数据及位置信息
    }
    
    return 0;
}
