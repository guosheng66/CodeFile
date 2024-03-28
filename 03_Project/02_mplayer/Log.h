#ifndef __LOG_H__
#define __LOG_H__

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>

/* 定义日志文件路径 */
#define LOG_PATH        "./Log"

/* 日志消息类型 */
typedef enum LogLevel
{
    LOG_FATAL,   //严重错误
    LOG_ERROR,   //错误
    LOG_WARNING, //告警
    LOG_MESSAGE, //消息
}LogLevel_t;

/* 文件日期信息 */
typedef struct date
{
    int year;
    int mon;
    int day;
}Date_t;

extern int LogInit(void);
extern int LogWrite(LogLevel_t level, char *pStr, ...);
extern int LogDeInit(void);
extern int LogSetLevel(LogLevel_t level);

#endif