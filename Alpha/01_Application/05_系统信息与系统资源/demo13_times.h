/* 这个程序没有运行成功，权限不够，sudo给权限也没用 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    struct tms t_buf_start;
    struct tms t_buf_end;
    clock_t t_start;
    clock_t t_end;
    long tck;
    int i = 0;
    int j = 0;

    /* 获取系统的节拍率  */
    tck = sysconf(_SC_CLK_TCK);
    
    /* 开始时间 */
    t_start = times(&t_buf_start);
    if (-1 == t_start)
    {
        perror("times() error");
        return -1;
    }

    /* 需要进行测试的代码段 */
    for (i = 0; i < 20000; i++)
    {
        for (j = 0; j < 20000; j++)
        {
        }
        sleep(1);
    }

    /* 结束时间 */
    t_end = times(&t_buf_end);
    if (-1 == t_end)
    {
        perror("times() error");
        return -1;
    }

    /* 打印时间 */
    printf("时间总和：%f秒\n", (t_end - t_start) / (double)tck);
    printf("用户CPU时间：%f秒\n", (t_buf_end.tms_utime - t_buf_start.tms_utime) / (double)tck);
    printf("系统CPU时间：%f秒\n", (t_buf_end.tms_stime - t_buf_start.tms_stime) / (double)tck);
    
    return 0;
}
