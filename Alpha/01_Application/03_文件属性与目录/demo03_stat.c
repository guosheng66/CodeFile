/*
 * 获取文件的时间属性，包括文件最后被访问的时间、文件内容最后被修改的
 * 时间以及文件状态最后被改变的时间，并使用字符串形式将其打印出来，包
 * 括时间和日期、表示形式自定。
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main(void)
{
    struct stat file_stat;
    struct tm file_tm;
    char time_str[100];
    int ret = 0;

    /* 获取文件属性 */
    ret = stat("test.file", &file_stat);
    if (ret == -1)
    {
        perror("stat error");
        exit(-1);
    }

    /* 打印文件最后被访问的时间 */
    localtime_r(&file_stat.st_atime, &file_tm);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", &file_tm);
    printf("time of last access:%s\n", time_str);

    /* 打印文件状态最后改变的时间 */
    localtime_r(&file_stat.st_ctime, &file_tm);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", &file_tm);
    printf("time of last status change: %s\n", time_str);

    exit(0);
}