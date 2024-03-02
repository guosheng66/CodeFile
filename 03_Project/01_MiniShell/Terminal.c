#include "Terminal.h"
#include "Command.h"

char gUserName[32] = {"Guosheng"};  //定义登陆账号
char gOsName[256] = {"minishell"};  //定义登陆名称

command_t gCmdList[]={
    {"cd", MyCd},
    {"chmod", MyChmod},
    {"ln", MyLn},
    {"ls", MyLs},   
    {"touch", MyTouch},
    {"pwd", MyPwd}, 
    {"exit", MyExit},
    {"mv", MyMv},
    {"cat", MyCat},
    {"cp", MyCp},
    {"rm", MyRm},
    {"rmdir", MyRmDir},
    {"mkdir", MyMkdir},
};

/********************************************
 * 函数名:ShowTerminal
 * 功能:打印用户与系统交互界面
 * 参数:
 * 		缺省
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
int ShowTerminal(void)
{
    char tmpbuff[4096] = {0}; //定义数组存放当前目录路径
    char *ptmp = NULL;

    getcwd(tmpbuff, sizeof(tmpbuff)); //获取当前目录路径

    ptmp = tmpbuff + sizeof(tmpbuff); //指针指向数组末尾

    /* 指针指向最后一个'/' */
    while (*ptmp != '/')
    {
        ptmp--;
    }
    ptmp--;

    /* 指针指向倒数第二个'/' */
    while (*ptmp != '/')
    {
        ptmp--;
    }

    /* 指针指向第二个目录名词首目录 */
    if (strcmp(tmpbuff, "/"))
    {
        ptmp++;
    }

    printf("\033[1;32m%s@%s\033[0m:\033[1;34m~/%s\033[0m$ ", 
            gUserName, gOsName, ptmp); //打印指令输入界面
    
    return 0;
}

/********************************************
 * 函数名:GetTerminal
 * 功能:获取用户输入的指令内容
 * 参数:
 * 		pCmdBuf：指向用户输入的指令数组的指针
 *      MaxLen：用户输入的指令个数
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
int GetTerminal(char *pCmdBuf, int MaxLen)
{
    fgets(pCmdBuf, MaxLen, stdin);       //向pCmdBuf指向的数组写入用户输入的指令
    pCmdBuf[strlen(pCmdBuf) - 1] = '\0'; //数组末尾加上'\0'

    return 0;
}

/********************************************
 * 函数名:ParseTerminal
 * 功能:解析用户输入的指令
 * 参数:
 * 		pCmdBuf：指向存储用户输入的指令数组的指针
 *      ppCmdArray：指向解析后的指令数组的指针
 *      MaxLen：用户输入的指令个数
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
int ParseTermainl(char *pCmdBuf, char **ppCmdArray, int MaxLen)
{
    int cnt = 0;

    ppCmdArray[cnt] = strtok(pCmdBuf, " "); //解析用户输入的指令

    /* 未接收命令返回cnt(0) */
    if (NULL == ppCmdArray[cnt])
    {
        return cnt;
    }
    cnt++;

    /* 将分段后的命令依次放入指针数组 */
    while ((ppCmdArray[cnt] = strtok(NULL, " ")) != NULL)
    {
        cnt++;
    }
    
    return cnt;
}

/********************************************
 * 函数名:ExecCommand
 * 功能:执行用户输入的命令
 * 参数:
 *      ppCmdArray：指向解析后的指令数组的指针
 *      CurCnt：用户输入的指令个数
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
int ExecCommand(char **ppCmdArray, int CurCnt)
{
	int CurCmdLen = sizeof(gCmdList) / sizeof(gCmdList[0]); //定义Shell命令长度
	int i = 0;
	int ret = 0;

    /* 判断输入的命令并执行相关函数 */
	for (i = 0; i < CurCmdLen; i++)
	{
		if (!strcmp(ppCmdArray[0], gCmdList[i].cmdname))
		{
			ret = gCmdList[i].pcmdfun(ppCmdArray, CurCnt);
		}
        else
        {
            printf("%s: 未找到命令\n", ppCmdArray[0]);
            return ret;
        }
	}

	return ret;
}
