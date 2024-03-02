#include "Log.h"
#include "Terminal.h"

int main(int argc, char const *argv[])
{
    char CommandBuff[4096] = {0}; //存储输入的命令
    char *pCmdArray[10] = {NULL}; //存储解析后的命令
    int CurCnt = 0;               //存储解析后的命令个数

    LogInit("Log.txt"); //日志记录文件初始化

    /* minishell执行流程 */
    while (1)
    {
        ShowTerminal();                                     //打印终端显示界面
        GetTerminal(CommandBuff, sizeof(CommandBuff));      //获取用户输入的指令并存储
        LogWrite(CommandBuff);                              //将用户输入的指令记录
        CurCnt = ParseTermainl(CommandBuff, pCmdArray, 10); //解析用户输入的命令
        ExecCommand(pCmdArray, CurCnt);                     //根据输入的命令执行相应函数
    }

    LogDeInit(); //关闭日志文件流指针，结束记录
     
    return 0;
}
