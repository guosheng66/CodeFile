#include <stdio.h>

void ShellSort(int arr[], int len)
{
    int i = 0;
    int j = 0;
    int gap = 0;
    int temp = 0;

    for (gap = len >> 1; gap > 0; gap >>= 1)
    {
        for (i = gap; i < len; i++)
        {
            temp = arr[i];
            
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
            {
                arr[j + gap] = arr[j];
            }

            arr[j + gap] = temp;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 3, 6, 7, 2, 9, 31, 11, 99, 88, 66};
    int len = 0;
    int i = 0;

    len = sizeof(arr) / sizeof(arr[0]);

    ShellSort(arr, len);

    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("");
    
    return 0;
}
