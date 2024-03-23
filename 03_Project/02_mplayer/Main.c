#include "Public.h"

int main(int argc, char const *argv[])
{
    int cmd = 0;

    // signal(SIGCHLD, handler);

    LogInit(MPLAYER_LOGFILE_PATH);
    LoadMediaFile(MPLAYER_MEDIADIR_PATH);

    while (1)
    {
        MenuShow();
        MenuChoose(&cmd);
        MenuExecCommand(cmd);

        /* 用户输入9时为程序退出功能 */
        if (9 == cmd)
        {
            break;
        }
    }

    LogDeInit();

    return 0;
}
