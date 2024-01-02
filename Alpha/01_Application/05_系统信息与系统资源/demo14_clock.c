#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    clock_t t_start;
    clock_t t_end;
    int i = 0;
    int j = 0;

    /* 开始时间 */
    t_start = clock();
    if (-1 == t_start)
    {
        perror("clock() error");
        return -1;
    }

    /* 需要测试的代码段 */
    for (i = 0; i < 2000; i++)
    {
        for (j = 0; j < 2000; j++)
        {
        }
    }

    t_end = clock();
    if (-1 == t_end)
    {
        perror("clock() error");
        return -1;
    }

    /* 打印时间 */
    printf("总的CPU时间：%fs\n", (t_end - t_start) / (double)CLOCKS_PER_SEC);    

    return 0;
}
