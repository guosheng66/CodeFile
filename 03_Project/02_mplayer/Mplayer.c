#include "Public.h"

/* 管理播放列表全局结构 */
MediaList_t gMediaList;

/* 管理播放状态全局结构 */
MediaStat_t gMediaStat;

/* mplayer进程PID */
pid_t pid;

/*******************************************
 * 函数名：IsMediaFile
 * 功能：查找文件夹中的音视频文件
 * 参数：
 *      char *pFileName：文件名称
 * 返回值：
 *      音视频文件返回1
 *      非音视频文件返回0
 * 注意事项：无
 *******************************************/
int IsMediaFile(char *pFileName)
{
    char *ptmp = NULL;

    ptmp = pFileName + strlen(pFileName); //ptmp指向文件名字符串的末尾

    /* 从文件名字符串的末尾向前搜索直到找到文件扩展名的点号或者到达字符串的开头 */
    while (ptmp >= pFileName && *ptmp != '.')
    {
        ptmp--;
    }

    if (!strcasecmp(ptmp, ".mp3") || !strcasecmp(ptmp, ".mp4") || !strcasecmp(ptmp, ".flv"))
    {
        return 1;
    }

    return 0;
}

/*******************************************
 * 函数名：LoadMediaFile
 * 功能：
 * 参数：
 *      char *pDirName：目录名称
 * 返回值：
 *      成功返回加载的媒体文件个数
 *      失败返回-1
 * 注意事项：无
 *******************************************/
int LoadMediaFile(const char *pDirName)
{
    DIR *dp = NULL;
    struct dirent *pp = NULL;

    dp = opendir(pDirName);
    if (NULL == dp)
    {
        LogWrite("open media dir error, load media failed");
        return -1;
    }

    while (1)
    {
        pp = readdir(dp);
        if (pp == NULL)
        {
            break;
        }
        if (pp->d_name[0] == '.')
        {
            continue;
        }

        if (gMediaList.curmediacnt < MPLAYER_MEDIALIST_MAXLEN && IsMediaFile(pp->d_name))
        {
            sprintf(gMediaList.medialist[gMediaList.curmediacnt], "%s/%s", pDirName, pp->d_name);
            gMediaList.curmediacnt++;
        }
    }

    closedir(dp);

    return gMediaList.curmediacnt;
}

/********************************************
 * 函数名：ShowMediaList
 * 功能：显示当前文件夹的音视频文件,接收用户指令并执行
 * 参数：缺省
 * 返回值：
 *      成功返回0
 * 注意事项：无
 ********************************************/
int ShowMediaList(void)
{
    int i = 0;
    int cmd = 0;
    int ret = 0;

    printf("cnt: %d\n", gMediaList.curmediacnt);
    for (i = 0; i < gMediaList.curmediacnt; i++)
    {
        printf("%2d.%s\n", i + 1, gMediaList.medialist[i]);
    }

    while (1)
    {
        printf("请选择播放文件，按0返回上一级\n");
        scanf("%d", &cmd);
        getchar();
        if (0 == cmd)
        {
            break;
        }

        if (gMediaStat.curstat != MPLAYER_STAT_FREE)
        {
            kill(pid, SIGKILL);
        }

        ret = PlayMedia(gMediaList.medialist[cmd - 1]);
        if (0 == ret)
        {
            gMediaStat.curmedianum = cmd -1;
        }
    }


    return 0;
}

/*******************************************
 * 函数名：PlayMediaFile
 * 功能：播放指定的音视频文件
 * 参数：
 *      char *pMeidaPath：文件路径
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 *******************************************/
int PlayMedia(char *pMediaPath)
{
    char fifopath[256] = {0};
    pid = fork();
    if (-1 == pid)
    {
        LogWrite("mplayer start error, play media failed");
        return -1;
    }

    if (0 == pid)
    {
        sprintf(fifopath, "file = %s", MPLAYER_FIFO_PATH);

        close(1);
        close(2);
        execlp("mplayer", "mplayer", "-slave", "input", fifopath, pMediaPath, "-quiet", NULL);
    }

    gMediaStat.curstat = MPLAYER_STAT_PLAY;
    gMediaStat.curspeed = MPLAYER_SPEED_ONE;

    return 0;
}

/*******************************************
 * 函数名：Stop()
 * 功能：停止播放
 * 参数：缺省
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 *******************************************/
int Stop(void)
{
    int fifd = 0;

    if (gMediaStat.curstat == MPLAYER_STAT_FREE)
    {
        return 0;
    }

    fifd = open(MPLAYER_FIFO_PATH, O_RDWR);
    if (-1 == fifd)
    {
        LogWrite("open mplayer input fifo error, stop media failed");
        return -1;
    }

/* 写入暂停信号 */
#if 0
    write(fifd, "pause\n", 6);
#endif
    

    kill(pid, SIGKILL);
    close(fifd);

    gMediaStat.curstat = MPLAYER_STAT_FREE;
    gMediaStat.curspeed = MPLAYER_SPEED_ONE;


    return 0;
}

/*******************************************
 * 函数名：Pause
 * 功能：暂停
 * 参数：缺省
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 *******************************************/
int Pause(void)
{
    int fifd = 0;

    fifd = open(MPLAYER_FIFO_PATH, O_RDWR);
    if (-1 == fifd)
    {
        LogWrite("open mplayer input fifo error, pause media failed");
        return -1;
    }

    write(fifd, "pause\n", 6);

    close(fifd);
    gMediaStat.curstat = MPLAYER_STAT_PAUSE;

    return 0;
}


/*******************************************
 * 函数名：PlayPause
 * 功能：开始暂停
 * 参数：缺省
 * 返回值：
 *      成功返回0
 * 注意事项：无
 *******************************************/
int PlayPause(void)
{
    int ret = 0;
    int n = 0;

    if (gMediaStat.curstat == MPLAYER_STAT_PLAY)
    {
        Pause();
    }
    else if (gMediaStat.curstat == MPLAYER_STAT_PAUSE)
    {
        Continue();
    }
    else if (gMediaStat.curstat == MPLAYER_STAT_FREE)
    {
        if (gMediaStat.curmode == MPLAYER_MODE_SINGLE)
        {
            PlayMedia(gMediaList.medialist[gMediaStat.curmedianum]);
        }
        else if (gMediaStat.curmode == MPLAYER_MODE_ORDER)
        {
            if (gMediaStat.curmedianum + 1 > gMediaList.curmediacnt)
            {
                printf("播放列表到达末尾\n");
                return 0;
            }

            ret = PlayMedia(gMediaList.medialist[gMediaStat.curmedianum + 1]);
            if (0 == ret)
            {
                gMediaStat.curmedianum++;
            }
        }
        else if (gMediaStat.curmode == MPLAYER_MODE_RANDOM)
        {
            n = rand() % gMediaList.curmediacnt;
            ret = PlayMedia(gMediaList.medialist[n]);
            if (0 == ret)
            {
                gMediaStat.curmedianum = n;
            }
        }
    }

    return 0;
}

/*******************************************
 * 函数名：Continue
 * 功能：继续播放
 * 参数：缺省
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 *******************************************/
int Continue(void)
{
    int fifd = 0;
    
    fifd = open(MPLAYER_FIFO_PATH, O_RDWR);
    if (-1 == fifd)
    {
        LogWrite("open mplayer input fifo error, continue media failed");
        return -1;
    }

    write(fifd, "pause\n", 6);
    
    close(fifd);

    gMediaStat.curstat = MPLAYER_STAT_PLAY;
    
    return 0;
}