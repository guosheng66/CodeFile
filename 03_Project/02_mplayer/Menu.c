#include "Public.h"

MenuOpt_t gMenuOptList[] = {
    {1, "查看播放列表", ShowMediaList},
    {2, "开始/暂停", PlayPause},
    {3, "停止", Stop},
    // {4, "上一曲", PreMedia},
    // {5, "下一曲", NextMedia},
    // {6, "快进", AddSpeed},
    // {7, "定位", SeekMedia},
    // {8, "播放模式", SetMode},
    // {9, "退出", Exit},
};

/*******************************************
 * 函数名：MenuShow
 * 功能：打印用户界面
 * 参数：缺省
 * 返回值：
 *      成功返回0
 * 注意事项：无
 *******************************************/
int MenuShow(void)
{
    int i = 0;
    int CurMediaOptLen = sizeof(gMenuOptList) / sizeof(gMenuOptList[0]);

    printf("\033[2J\033[0;0H");
    printf("\033[47;34m======================================\033[0m\n");
    printf("\033[47;34m              媒体播放器              \033[0m\n");
    printf("\033[47;34m======================================\033[0m\n");

    for (i = 0; i < CurMediaOptLen; i++)
    {
        printf("\033[47;34m|    \033[0m");
        printf("%d.%s\n", gMenuOptList[i].id, gMenuOptList[i].content);
    }

    printf("\033[47;34m======================================\033[0m\n");

    return 0;
}

/*******************************************
 * 函数名：MenuChoose
 * 功能：接收用户指令
 * 参数：
 *      *pNum：存储用户输入指令的地址
 * 返回值：
 *      成功返回0
 * 注意事项：无
 *******************************************/
int MenuChoose(int *pNum)
{
    printf("请选择：");
    scanf("%d", pNum);
    getchar();

    return 0;
}

/*******************************************
 * 函数名：MenuExecCommand
 * 功能：执行相应功能
 * 参数：
 *      int cmd：用户输入的指令
 * 返回值：
 *      成功返回0
 * 注意事项：无
 *******************************************/
int MenuExecCommand(int cmd)
{
    int CurMediaOptLen = sizeof(gMenuOptList) / sizeof(gMenuOptList[0]);
    int i = 0;
    int ret = 0;

    for (i = 0; i < CurMediaOptLen; i++)
    {
        if (gMenuOptList[i].id == cmd)
        {
            ret = gMenuOptList[i].pfun();
            break;
        }
    }

    return ret;
}