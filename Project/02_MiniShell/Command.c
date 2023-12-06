#include "Command.h"

/*************************************************
 * 函数名：MyCd
 * 功能：切换当前工作目录
 * 参数：
 *      ppCmdArray:指向解析后的指令数组的指针
 *      CurCnt:解析后的命令个数
 * 返回值:
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 *************************************************/
int MyCd(char **ppCmdArray, int CurCnt)
{
    /* 判断用户输入命令模式是否正确（入口参数检查） */
    if (2 != CurCnt)
    {
        fprintf(stderr, "Usage: cd mode filename\n");
        return -1;
    }

    /* 切换工作目录 */
    if (ppCmdArray[1] != NULL)
    {
        chdir(ppCmdArray[1]);
    }

    return 0;
}

/*************************************************
 * 函数名：MyCd
 * 功能：切换当前工作目录
 * 参数：
 *      ppCmdArray:指向解析后的指令数组的指针
 *      CurCnt:解析后的命令个数
 * 返回值:
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 *************************************************/
int MyChmod(char **ppCmdArray, int CurCnt)
{
    mode_t mode;
    char *p = NULL;

    /* 判断用户输入命令模式是否正确 */
    if (3 != CurCnt)
    {
        fprintf(stderr, "Usage:chmod mode filename\n");
    }

    p = ppCmdArray[1];
    while (*p != '\0')
    {
        mode = mode * 8 + *p - '0'; //将输入的代表权限的数字转换为8禁止数字
    }
    
    chmod(ppCmdArray[2], mode);     //修改文件权限

    return 0;
}

/*************************************************
 * 函数名：MyLn
 * 功能：为某一个文件在另外一个位置建立一个同步的链接
 * 参数：
 *      ppCmdArray:指向解析后的指令数组的指针
 *      CurCnt:解析后的命令个数
 * 返回值:
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 *************************************************/
int MyLn(char **ppCmdArray, int CurCnt)
{
    /* 判断用户输入命令模式是否正确 */
    if (CurCnt < 3)
    {
        fprintf(stderr, "Usage:ln [-s] src.txt link.txt\n");
        return -1;
    }
    
    if (3 == CurCnt)
    {
        link(ppCmdArray[1], ppCmdArray[2]);
    }
    else if (4 == CurCnt && !strcmp(ppCmdArray[1], "-s"))
    {
        symlink(ppCmdArray[2], ppCmdArray[3]);
    }

    return 0;
}

/*************************************************
 * 函数名：MyMv
 * 功能：移动文件，改变目录或文件名称
 * 参数：
 *      ppCmdArray:指向解析后的指令数组的指针
 *      CurCnt:解析后的命令个数
 * 返回值:
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 *************************************************/
int MyMv(char **ppCmdArray, int CurCnt)
{
    int ret = 0;
    struct stat buf;
    char newpath[1024] = {0};

    /* 判断用户输入命令是否正确 */
    if (CurCnt != 3)
    {
        fprintf(stderr, "Usage: mv srcfile dstpath");
        return -1;
    }

    ret = stat(ppCmdArray[2], &buf);
    if (0 == ret && S_ISDIR(buf.st_mode))
    {
        sprintf(newpath, "%s/%s", ppCmdArray[2], ppCmdArray[1]);
    }
    else
    {
        sprintf(newpath, "%s", ppCmdArray[2]);
    }  

    ret = rename(ppCmdArray[1], newpath); 
    if (-1 == ret)
    {
        perror("fail to rename");
        return -1;
    } 
}

/*************************************************
 * 函数名：MyLs
 * 功能：打印当前目录的列表
 * 参数：
 *      ppCmdArray:指向解析后的指令数组的指针
 *      CurCnt:解析后的命令个数
 * 返回值:
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 *************************************************/
int MyLs(char **ppCmdArray, int CurCnt)
{
    char tmpbuff[4096] = {0}; //存放当前目录路径
    DIR *dp = NULL;           //定义DIR结构体的指针dp
    struct dirent *pp = NULL; //指向结构体dirent 
}
int MyTouch(char **ppCmdArray, int CurCnt);
int MyPwd(char **ppCmdArray, int CurCnt);
int MyExit(void);
MyCat(char **pCmdArray, int CurCnt);
MyCp(char **ppCmdArray, int CurCnt);
MyRm(char **ppCmdArray, int CurCnt);
MyRmDir(char **ppCmdArray, int CurCnt);
MyMkDir(char **ppCmdArray, int CurCnt);
void StatFile(char *pFileName);