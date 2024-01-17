#ifndef __TERMINAL_H__
#define __TERMINAL_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* Shell命令类型 */
typedef struct command
{
    char cmdname[32];             //命令字符串
    int (*pCmdFun)(char **, int); //命令对应的函数入口
                                  //函数指针，接收两个参数
                                  //指向应该在执行该命令时调用的函数
}command_t;

extern int ShowTerminal(void);
extern int GetTerminal(char *pCmdBuf, int MaxLen);
extern int ParseCommand(char *pCmdBud, char **ppCmdArray, int Maxlen);
extern int ExecCommand(char **ppCmdArray, int CurCnt);

#endif