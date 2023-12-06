/* 示例为快速排序 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 16

int Partion(int *data, int low, int high);
int QuickSort(int *data, int low, int high);
int Compare(const void *p1, const void *p2);

int main(int argc, char const *argv[])
{
    int data[N] = {0}; //存储数据进行排序
    int i = 0;

    srandom(10);       //设置种子，以产生较好的随机数
    
    /* 向数组中添加数据 */
    for (i = 0; i < N; i++)
    {
        data[i] = random() % 100;
    }

    /* 打印数组中的数据 */
    for (i = 0; i < N; i++)
    {
        printf("%d ", data[i]);
    }
    puts("");

    QuickSort(data, 0, N-1);
    // qsort(data, N, sizeof(int), Compare); //直接调用库函数qsort进行快速排序

    for (i = 0; i < N; i++)
    {
        printf("%d ", data[i]);
    }
    puts("");

    
    return 0;
}

/***********************************************
 * 函数名：Partion
 * 功能：找到数据中轴
 * 参数：
 *      int *data:进行排序的数组
 *      int low:数组的第一个数据的下标 *      
 *      int high:数组最后一个元素的下标
 * 返回值：
 *      成功返回中轴坐标
 * 注意事项：无
 ***********************************************/
int Partion(int *data, int low, int high)
{
    int temp = data[low];
    
    while (low < high)
    {
        while (low < high && temp <= data[high])
        {
            high--;
        }
        data[low] = data[high];

        while (low < high && temp >= data[low])
        {
            low++;
        }
        data[high] = data[low];
    }

    data[low] = temp;

    return low;
}

/***********************************************
 * 函数名：QucikSort
 * 功能：快速排序
 * 参数：
 *      int *data:进行排序的数组
 *      int low:数组第一个元素的下标
 *      int high:数组最后一个元素的下标
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ***********************************************/
int QuickSort(int *data, int low, int high)
{
    int t = 0;

    /* 判断参数是否合法（数组是否为空） */
    if (data == NULL)
    {
        return -1;
    }

    /* 递归出口 */
    if (low >= high)
    {
        return 0;
    }

    t = Partion(data, low, high);
    QuickSort(data, low, t-1);
    QuickSort(data, t+1, high);

    return 0;
}

/***********************************************
 * 函数名：Compare
 * 功能：比较两个数字的大小
 * 参数：
 *      const void *p1:待比较的第一个数的地址
 *      const void *p2:待比较的第二个数的地址
 * 返回值：
 *      返回两个数相减的结果
 * 注意事项：无
 ***********************************************/
int Compare(const void *p1, const void *p2)
{
    return (*(const int *)p1 - *(const int *)p2);
}
