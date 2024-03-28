#include "Public.h"
#include "Log.h"

int main(int argc, char const *argv[])
{
    int cmd = 0; //定义变量用来接收用户输入的指令

    LogInit();
    LoadMediaFile(MPLAYER_MEDIADIR_PATH);

    LogWrite(LOG_MESSAGE, "\n");
    LogWrite(LOG_MESSAGE, "\n");
    LogWrite(LOG_MESSAGE, "============================================\n");
    LogWrite(LOG_MESSAGE, "============================================\n");
    LogWrite(LOG_MESSAGE, "         媒体播放器启动，开始日志记录            \n");
    LogWrite(LOG_MESSAGE, "============================================\n");
    LogWrite(LOG_MESSAGE, "============================================\n");

    while (1)
    {
        MenuShow();
        MenuChoose(&cmd);
        ExecCommand(cmd);

        if (9 == cmd)
        {
            break;
        }
    }

    LogWrite(LOG_MESSAGE, "============================================\n");
    LogWrite(LOG_MESSAGE, "============================================\n");
    LogWrite(LOG_MESSAGE, "         媒体播放器关闭，结束日志记录            \n");
    LogWrite(LOG_MESSAGE, "============================================\n");
    LogWrite(LOG_MESSAGE, "============================================\n");

    LogDeInit();
    
    return 0;
}
