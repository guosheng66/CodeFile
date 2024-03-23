#include "Public.h"

/* 日志文件流指针 */
FILE *fp = NULL;

/*******************************************
 * 函数名：LogInit
 * 功能：打开日志记录文件
 * 参数：
 *      const char *pLogFilePath：日志文件名称
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 *******************************************/
int LogInit(const char *pLogFilePath)
{
    fp = fopen(pLogFilePath, "a");
    if (NULL == fp)
    {
        fprintf(stderr, "日志文件打开失败，本次程序将没有日志记录");
        return -1;
    }

    return 0;
}

/*******************************************
 * 函数名：LogWrite
 * 功能：日志记录 
 * 参数：
 *      const char *pStr：程序出错信息
 * 返回值：
 *      成功返回0
 * 注意事项：无
 *******************************************/
int LogWrite(const char *pStr)
{
    time_t t;
    struct tm *ptm = NULL;

    time(&t);
    ptm = localtime(&t);
    fprintf(fp, "[%04d-%02d-%02d %02d:%02d]%s\n",
            ptm->tm_year + 1900, ptm->tm_mon +1, ptm->tm_mday,
            ptm->tm_hour, ptm->tm_min, pStr);

    fflush(fp);

    return 0;
}

/*******************************************
 * 函数名：LogDeInit
 * 功能：关闭日志记录文件
 * 参数：缺省
 * 返回值：
 *      成功返回0
 * 注意事项：无
 *******************************************/
int LogDeInit(void)
{
    if (NULL != fp)
    {
        fclose(fp);
    }

    return 0;
}