#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

extern int MyCd(char **ppCmdArray, int CurCnt);
extern int MyChmod(char **ppCmdArray, int CurCnt);
extern int MyLn(char **ppCmdArray, int CurCnt);
extern int MyMv(char **ppCmdArray, int CurCnt); 
extern int MyLn(char **ppCmdArray, int CurCnt);  
extern int MyLs(char **ppCmdArray, int CurCnt);
extern int MyTouch(char **ppCmdArray, int CurCnt); 
extern int MyPwd(char **ppCmdArray, int CurCnt);
extern void MyExit(void);     
extern int MyCat(char **ppCmdArray, int CurCnt);
extern int MyCp(char **ppCmdArray, int CurCnt);
extern int MyRm(char **ppCmdArray, int CurCnt);
extern int MyRmDir(char **ppCmdArray, int CurCnt);  
extern int MyMkdir(char **ppCmdArray, int CurCnt);
extern void StatFile(char *pfilename);

#endif