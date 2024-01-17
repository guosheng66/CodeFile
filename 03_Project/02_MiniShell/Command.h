#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

extern int MyCd(char **ppCmdArray, int CurCnt);
extern int MyChmod(char **ppCmdArray, int CurCnt);
extern int MyLn(char **ppCmdArray, int CurCnt);
extern int MyMv(char **ppCmdArray, int CurCnt);
extern int MyLs(char **ppCmdArray, int CurCnt);
extern int MyTouch(char **ppCmdArray, int CurCnt);
extern int MyPwd(char **ppCmdArray, int CurCnt);
extern int MyExit(void);
extern MyCat(char **pCmdArray, int CurCnt);
extern MyCp(char **ppCmdArray, int CurCnt);
extern MyRm(char **ppCmdArray, int CurCnt);
extern MyRmDir(char **ppCmdArray, int CurCnt);
extern MyMkDir(char **ppCmdArray, int CurCnt);
extern void StatFile(char *pFileName);

#endif