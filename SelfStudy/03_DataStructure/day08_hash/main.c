/* 示例为链式哈希 */
#include "hash.h"

int main(int argc, char const *argv[])
{
    hash *HT = NULL;   //定义一个哈希表
    int data[] = {23, 34, 14, 38, 46, 16, 68, 15, 7, 31, 26};
    int i = 0;         //辅助变量，循环使用
    int key = 0;       //
    linklist r = NULL;

    /* 创建一个空的哈希表，失败返回-1 */
    if ((HT = CreateHash()) == NULL)
    {
        return -1;
    }

    /* 将数组中的数据元素插入到哈希表中 */
    for (i = 0; i < sizeof(data) / sizeof(int); i++)
    {
        InsertHash(HT, data[i]);
    }

    /* 输入要查找的数据元素 */
    printf("Input:");
    scanf("%d", &key);

    r = SearchHash(HT, key);
    /* 判断数据是否找到 */
    if (r == NULL)
    {
        printf("not found\n");
    }
    else
    {
        printf("found: %d %d\n", key, r->key); //打印位置信息
    }
    
    return 0;
}
