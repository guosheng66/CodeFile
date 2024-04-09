#include <stdio.h>

void BubbleSort(int arr[], int len)
{
    int i = 0;
    int j = 0;
    int temp = 0;

    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 3, 6, 7, 2, 9, 31, 11, 99, 88, 66};
    int len = 0;
    int i = 0;

    len = sizeof(arr) / sizeof(arr[0]);
    
    BubbleSort(arr, len);
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("");

    return 0;
}
