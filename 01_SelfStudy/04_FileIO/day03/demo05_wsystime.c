#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    FILE *fp = NULL;
    time_t ctime = 0;
    struct tm *ctimestr;
    int linecnt = 0; 
    char buf[32] = {0};

    fp = fopen("time.txt", "a+");
    if (fp == NULL)
    {
        perror("fopen");
        return 0;
    }

    /* 获取文件行号 */
    while (fgets(buf, 32, fp) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
        {
            linecnt++;
        }
    }

    while (1)
    {
        ctime = time(NULL);
        ctimestr = localtime(&ctime);
        fprintf(fp, "[%d] [%04d-%02d-%02d %02d:%02d:%02d]\n", linecnt, 
                ctimestr->tm_year + 1900, ctimestr->tm_mon + 1, ctimestr->tm_mday,
                ctimestr->tm_hour, ctimestr->tm_min, ctimestr->tm_sec);
    
    fflush(fp);
    linecnt++;
    sleep(1);
    }

    return 0;
}
