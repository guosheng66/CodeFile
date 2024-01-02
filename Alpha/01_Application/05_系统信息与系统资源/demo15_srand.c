#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int random_num_arr[8] = {0};
    int cnt;

    /* 设置随机数种子 */
    srand(time(NULL));
    
    /* 生成伪随机数 */
    for (cnt = 0; cnt < 8; cnt++)
    {
        random_num_arr[cnt] = rand() % 100;
    }

    /* 打印随机数组 */
    printf("[");
    for (cnt = 0; cnt < 8; cnt++)
    {
        printf("%d", random_num_arr[cnt]);
        if (cnt != 8 - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
