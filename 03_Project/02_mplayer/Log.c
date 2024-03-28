#include "Log.h"

static FILE *fp = NULL; //声明静态文件指针
LogLevel_t gCurLogLevel = LOG_MESSAGE;
Date_t FileDate;

/****************************************
 * 函数名：LogInit
 * 功能：日志文件初始化
 * 参数：缺省
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ****************************************/
int LogInit(void)
{
    time_t t;
    struct tm *ptm = NULL;
    char dirpath[1024] = {0};
    char filepath[2048] = {0};

    mkdir(LOG_PATH, 0777);

    time(&t);
    ptm = localtime(&t);
    sprintf(dirpath, "%s/%04d%02d%02d", LOG_PATH, ptm->tm_year + 1900,
            ptm->tm_mon + 1, ptm->tm_mday);
    mkdir(dirpath, 0777);

    sprintf(filepath, "%s/debug_%04d%02d%02d.log", dirpath, ptm->tm_year+1900, 
            ptm->tm_mon+1, ptm->tm_mday);


    FileDate.year = ptm->tm_year + 1900;
    FileDate.mon = ptm->tm_mon + 1;
    FileDate.day = ptm->tm_mday;

    fp = fopen(filepath, "a");
    if (NULL == fp)
    {
        perror("fail to open(file of log)");
        return -1;
    }

    return 0;
}

/****************************************
 * 函数名：LogWrite
 * 功能：向日志文件中写入日志信息
 * 参数：
 *      LogLevel_t level：
 *      char *pStr:
 *      ...：可变参数
 * 返回值：
 *      成功返回0
 * 注意事项：无
 ****************************************/
int LogWrite(LogLevel_t level, char *pStr, ...)
{
    char *perrorstr[4] = {"严重错误", "错误", "警告", "消息"}; //不同级别的描述
    time_t t;
    struct tm *ptm = NULL;
    va_list ap; //可变数量参数列表

    /* 日志文件创建失败直接退出（参数检查） */
    if (NULL == fp)
    {
        return -1;
    }

    /* 如果传入的日志文件级别大于当前设置的日志级别，不进行日志记录 */
    if (level > gCurLogLevel)
    {
        return 0;
    }

    time(&t);            //获取当前时间
    ptm = localtime(&t); //将时间转换为本地时间

    /* 如果当前时间与文件日期不一致，则重新初始化日志文件 */
    if (FileDate.year != ptm->tm_year + 1900 || FileDate.mon != ptm->tm_mon + 1
        || FileDate.day != ptm->tm_mday)
    {
        LogDeInit();
        LogInit();
    }

    /* 将时间和日志级别写入日志文件 */
    fprintf(fp, "[%04d-%02d-%02d %02d:%02d:%02d] [%s]", ptm->tm_year + 1900,
            ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min,
            ptm->tm_sec, perrorstr[level]);
    
    /* 将日志内容写入文件 */
    va_start(ap, pStr);     //开始处理可变参函数列表，ap指向第一个可变参数
    vfprintf(fp, pStr, ap); //将可变参数列表根据格式字符串pStr写入到文件中
    va_end(ap);             //结束可变参数的处理

    fflush(fp); //刷新日志文件，确保内容写入文件    

    return 0;
}

/****************************************
 * 函数名：LogDeInit
 * 功能：销毁日志文件
 * 参数：缺省
 * 返回值：
 *      成功返回0
 * 注意事项：无
 ****************************************/
int LogDeInit(void)
{
    if (fp != NULL)
    {
        fclose(fp);
        fp = NULL;
    }

    return 0;
}

/****************************************
 * 函数名：LogSetLevel
 * 功能：设置日志级别
 * 参数：
 *      LogLevel_t level：日志级别
 * 返回值：
 *      成功返回0
 * 注意事项：无
 ****************************************/
int LogSetLevel(LogLevel_t level)
{
    LogWrite(LOG_FATAL, "日志级别切换为：%d -> %d\n", gCurLogLevel, level);
    gCurLogLevel = level;
    
    return 0;
}