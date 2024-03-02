#ifndef __TERMINAL_H__
#define __TERMINAL_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* shell命令类型 */
typedef struct command
{
    char cmdname[32];            //命令字符串
    int (*pcmdfun)(char **, int); //命令对应的函数入口
}command_t;

extern int ShowTerminal(void);
extern int GetTerminal(char *pCmdBuf, int MaxLen);
extern int ParseTermainl(char *pCmdBuf, char **ppCmdArray, int MaxLen);
extern int ExecCommand(char **ppCmdArray, int CurCnt);

#endif