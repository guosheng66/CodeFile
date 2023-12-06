#include "Log.h"

FILE *fp = NULL; //定义文件流指针

/**********************************************
 * 函数名：LogInit
 * 功能：日志文件初始化
 * 参数：
 *      pFileName:日志文件名称
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 **********************************************/
int LogInit(char *pFileName)
{
    fp = fopen(pFileName, "a");//以追加方式打开文件
    if (NULL == fp)
    {
        perror("fail to fopen");
        return -1;
    }

    return 0;
}

/**********************************************
 * 函数名：LogWrite
 * 功能：（实现记录）向日志文件中写入命令及其输入时间
 * 参数：
 *      *pStr:输入命令名称
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 **********************************************/
int LogWrite(char *pStr)
{
    time_t t;
    struct tm *ptm = NULL;

    time(&t);
    ptm = localtime(&t);
    fprintf(fp, "[%04d-%02d-%02d %02d:%02d:%02d]: %s\n", ptm->tm_year + 1900, ptm->tm_mon + 1,
                ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, pStr);
    fflush(fp); //刷新fp文件流的输出缓冲区
    
    return 0;
}

/**********************************************
 * 函数名：LogDeInit
 * 功能：关闭文件流指针
 * 参数：缺省
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 **********************************************/
int LogDeInit(void)
{
    fclose(fp);

    return 0;
}