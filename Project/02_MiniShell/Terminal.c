#include "Terminal.h"
#include "Command.h"

char gUserName[32] = {"Guosheng"}; //定义登录账号
char gOsName[32] = {"minishell"};  //定义登录名称

/* Shell命令类型数组 */
command_t gCmdList[] = {
    {"cd", MyCd},
    // {"chmod", Mychmod},
    // {"ln", MyLn},
    // {"ls", MyLs},
    // {"touch", MyTouch},
    // {"pwd", MyPwd},
    // {"exit", MyExit},
    // {"mv", MyMv},
    // {"cat", MyCat},
    // {"cp", MyCp},
    // {"rm", MyRm},
    // {"rmdir", MyRmDir},
    // {"mkdir", mkDir},
};

/*******************************************
 * 函数名：ShowTerminal
 * 功能：打印用户与系统交互界面
 * 参数：
 *      缺省
 * 返回值：
 *      成功返回0
 * 注意事项：
 *      无
 *******************************************/
int ShowTerminal(void)
{
    char tmpbuff[4096] = {0}; //存放当前工作路径
    char *ptmp = NULL;        //定义指针操作工作路径字符串
    
    getcwd(tmpbuff, sizeof(tmpbuff)); //将当前工作目录的绝对路径复制到tmpbuff数组
    ptmp = tmpbuff + strlen(tmpbuff); //指针指向数组末尾
    
    /* 操作指针指向最后一个'/' */
    while (*ptmp != '/')
    {
        ptmp--;
    }
    ptmp--; //指针指向最后一个'/'的前一个字符

    /* 指针指向倒数第二个'/' */
    while (*ptmp != '/')
    {
        ptmp--;
    }

    /* 指针指向倒数第二个目录名词首字母 */
    if (strcmp(tmpbuff, "/"))
    {
        ptmp++;
    }

    /* 打印指令输入界面 */
    printf("\033[1;32m%s@%s\033[0m:\033[1;34m~/%s\033[0m$ ", gUserName, gOsName, ptmp);

    return 0;
}

/*******************************************
 * 函数名：GetTerminal
 * 功能：获取用户输入的指令内容
 * 参数：
 *      pCmdBuf:指向用户输入的指令数组的指针
 *      MaxLen:用户输入的指令个数
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：
 *      无
 *******************************************/
int GetTerminal(char *pCmdBuf, int MaxLen)
{
    fgets(pCmdBuf, MaxLen, stdin);       //将标准输入流中的指令写入到pCmdBuf中
    pCmdBuf[strlen(pCmdBuf) - 1] = '\0'; //数组末尾加上结束标志

    return 0;
}

/*******************************************
 * 函数名：GetTerminal
 * 功能：获取用户输入的指令内容
 * 参数：
 *      pCmdBuf:指向用户输入的指令数组的指针
 *      MaxLen:用户输入的指令个数
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：
 *      无
 *******************************************/
int ParseCommand(char *pCmdBuf, char **ppCmdArray, int Maxlen)
{
    int cnt = 0; //存储解析后获得的指令个数
    
    ppCmdArray[cnt] = strtok(pCmdBuf, " ");

    /* 未接收命令返回-1 */
    if (ppCmdArray[cnt] == NULL)
    {
        return cnt;
    }

    return 0;
}
int ExecCommand(char **ppCmdArray, int CurCnt)
{
    int CurCmdLen = sizeof(gCmdList) / sizeof(gCmdList[0]); //定义shell命令长度
    int i = 0;
    int ret = 0;

    /* 判断输入的命令并执行相关函数 */
    for (i = 0; i < CurCmdLen; i++)
    {
        if (!strcmp(ppCmdArray[0], gCmdList[i].cmdname))
        {
            ret = gCmdList[i].pCmdFun(ppCmdArray, CurCnt);
        }
    }

    return 0;
}