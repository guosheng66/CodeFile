#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp = 0;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

void SelectSort(int arr[], int len)
{
    int i = 0;
    int j = 0;
    int min = 0;

    for (i = 0; i < len - 1; i++)
    {
        min = i;
        
        /* 查找所有数据元素中的最小值 */
        for (j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            
            Swap(&arr[min], &arr[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 3, 6, 7, 2, 9, 31, 11, 99, 88, 66};
    int len = 0;
    int i = 0;

    len = sizeof(arr) / sizeof(arr[0]);

    SelectSort(arr, len);

    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("");
    
    return 0;
}
