#include "Public.h"
#include "Log.h"

int gMediaFileTotalNum = 0;
int gCmd = 1;
MediaList_t gMediaList; //管理播放列表全局结构
MediaStat_t gMediaStat; //管理播放状态全局结构

pid_t pid;              //mplayer进程ID

/****************************************
 * 函数名：
 * 功能：
 * 参数：
 * 返回值：
 * 注意事项：无
 ****************************************/

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
        LogWrite(LOG_ERROR, "open media dir error, load media failed");
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

        if (gMediaList.CurMediaCnt < MPLAYER_MEDIALIST_MAXLEN && IsMediaFile(pp->d_name))
        {
            sprintf(gMediaList.medialist[gMediaList.CurMediaCnt], "%s", pp->d_name);
            gMediaList.CurMediaCnt++;
        }
    }

    gMediaFileTotalNum = gMediaList.CurMediaCnt;

    closedir(dp);

    return gMediaList.CurMediaCnt;
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
    int ret = 0;

    while (1)
    {
        /* 打印当前播放列表 */
        for (i = 0; i < gMediaList.CurMediaCnt; i++)
        {
            printf("%2d.%s\n", i + 1, gMediaList.medialist[i]);
        }

        printf("请选择播放文件，按0返回上一级\n");
        scanf("%d", &gCmd);
        getchar();
        if (0 == gCmd)
        {
            break;
        }

        if (gMediaStat.curstat != MPLAYER_STAT_FREE)
        {
            kill(pid, SIGKILL);
        }

        ret = PlayMedia(gMediaList.medialist[gCmd - 1]);
        if (0 == ret)
        {
            gMediaStat.curmedianum = gCmd -1;
        }  

        system("clear");              
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
    char filepath[256] = {0};
    
    pid = fork();
    if (-1 == pid)
    {
        LogWrite(LOG_ERROR, "mplayer start error, play media failed");
        return -1;
    }
    if (0 == pid)
    {
        sprintf(fifopath, "file=%s", MPLAYER_FIFO_PATH);
        sprintf(filepath, "%s/%s", MPLAYER_MEDIADIR_PATH, pMediaPath);

        close(1);
        close(2);

        execlp("mplayer", "mplayer", "-slave", "-input", fifopath, filepath, NULL);
        LogWrite(LOG_ERROR, "child process exec mplayer(%s) failed\n", pMediaPath);
        
        exit(0);
    }

    gMediaStat.curstat = MPLAYER_STAT_PLAY;
    gMediaStat.curspeed = MPLAYER_SPEED_ONE;

    LogWrite(LOG_MESSAGE, "Mplayer play %s success\n", pMediaPath);

    return 0;
}

/*******************************************
 * 函数名：PlayPause
 * 功能：开始暂停
 * 参数：缺省
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 *******************************************/
int PlayPause(void)
{
    int fd = 0;
    int ret = 0;
    
    fd = open(MPLAYER_FIFO_PATH, O_RDWR);
    if (-1 == fd)
    {
        LogWrite(LOG_ERROR, "open mplayer input fifo failed, can't pause mplayer\n");
        return -1;
    }

    ret = write(fd, "pause\n", strlen("pause\n"));
    if (-1 == ret)
    {
        LogWrite(LOG_ERROR, "write pause into fifo failed, can't pause mplayer\n");
    }

    close(fd);

    if (gMediaStat.curstat == MPLAYER_STAT_PLAY)
    {
        gMediaStat.curstat = MPLAYER_STAT_PAUSE;
        LogWrite(LOG_MESSAGE, "媒体状态切换为：暂停状态\n");
    }
    else if (gMediaStat.curstat == MPLAYER_STAT_PAUSE)
    {
        gMediaStat.curstat = MPLAYER_STAT_PLAY;
        LogWrite(LOG_MESSAGE, "媒体状态切换为：播放状态\n");
    }

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

    if (gMediaStat.curstat != MPLAYER_STAT_FREE)
    {
        kill(pid, SIGKILL);
        gMediaStat.curstat = MPLAYER_STAT_FREE;
        gMediaStat.curspeed = MPLAYER_SPEED_ONE;
        LogWrite(LOG_MESSAGE, "停止播放媒体文件\n");
    }

    return 0;
}

/*******************************************
 * 函数名：PreMedia
 * 功能：播放上一个文件
 * 参数：缺省
 * 返回值：
 *      成功返回0
 * 注意事项：无
 *******************************************/
int PreMedia(void)
{
    int n = 0;
    int ret = 0;
    int random_number = 0;

    if (gMediaStat.curstat == MPLAYER_STAT_PLAY)
    {
        kill(pid, SIGKILL);
        gMediaStat.curstat = MPLAYER_STAT_FREE;
    }
    
    /* 循环播放 || 顺序播放 */
    if (gMediaStat.curmode == MPLAYER_MODE_LOOP || gMediaStat.curmode == MPLAYER_MODE_ORDER)
    {
        gCmd = gCmd - 1;
        
        if (gCmd < 0)
        {
            gCmd = gMediaList.CurMediaCnt - 1; 
        }

        PlayMedia(gMediaList.medialist[gCmd]);
    }
    else if (gMediaStat.curmode == MPLAYER_MODE_RANDOM)
    {
        srand(time(NULL));
        random_number = rand() % gMediaList.CurMediaCnt;
        ret = PlayMedia(gMediaList.medialist[random_number]);        
        if (0 == ret)
        {
            gMediaStat.curmedianum = n;
        }
    }

    printf("按任意键返回上一层\n");
    getchar();

    return 0;
}

/*******************************************
 * 函数名：NextMedia
 * 功能：播放下一个文件
 * 参数：缺省
 * 返回值：
 *      成功返回0
 * 注意事项：无
 *******************************************/
int NextMedia(void)
{
    int n = 0;
    int ret = 0;
    int random_number = 0;

    if (gMediaStat.curstat == MPLAYER_STAT_PLAY)
    {
        kill(pid, SIGKILL);
        gMediaStat.curstat = MPLAYER_STAT_FREE;
    }
    
    /* 循环播放 || 顺序播放 */
    if (gMediaStat.curmode == MPLAYER_MODE_LOOP || gMediaStat.curmode == MPLAYER_MODE_ORDER)
    {
        gCmd = gCmd + 1;
        
        if (gCmd == (gMediaFileTotalNum))
        {
            gCmd = 0; 
        }

        PlayMedia(gMediaList.medialist[gCmd]);
    }
    else if (gMediaStat.curmode == MPLAYER_MODE_RANDOM)
    {
        srand(time(NULL));
        random_number = rand() % gMediaList.CurMediaCnt;
        ret = PlayMedia(gMediaList.medialist[random_number]);        
        if (0 == ret)
        {
            gMediaStat.curmedianum = n;
        }
    }

    printf("按任意键返回上一层\n");
    getchar();

    return 0;
}

/*******************************************
 * 函数名：AddSpeed
 * 功能：快进
 * 参数：缺省
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 *******************************************/
int AddSpeed(void)
{
    int fifd = 0;

    if (gMediaStat.curstat != MPLAYER_STAT_PLAY)
    {
        return 0;
    }

    fifd = open(MPLAYER_FIFO_PATH, O_RDWR);
    if (-1 == fifd)
    {
        LogWrite(LOG_ERROR, "open mplayer input fifo error, add media speed failed");
        return -1;
    }

    if (gMediaStat.curspeed == MPLAYER_SPEED_ONE)
    {
        write(fifd, "speed_set 2\n", 12);
        gMediaStat.curspeed = MPLAYER_SPEED_TWO;
        printf("当前播放速度：快进 ✖ 2\n");
        LogWrite(LOG_MESSAGE, "快进 ✖ 2\n");
    }
    else if (gMediaStat.curspeed == MPLAYER_SPEED_TWO)
    {
        write(fifd, "speed_set 4\n", 12);
        gMediaStat.curspeed = MPLAYER_SPEED_FOUR;
        printf("当前播放速度：快进 ✖ 4\n");
        LogWrite(LOG_MESSAGE, "快进 ✖ 4\n");
    }
    else if (gMediaStat.curspeed == MPLAYER_SPEED_FOUR)
    {
        write(fifd, "speed_set 1\n", 12);
        gMediaStat.curspeed = MPLAYER_SPEED_ONE;
        printf("当前播放速度：快进 ✖ 8\n");
        LogWrite(LOG_MESSAGE, "快进 ✖ 1\n");
    }

    close(fifd);
    
    printf("按任意键返回上一层\n");
    getchar();

    return 0;
}

/*******************************************
 * 函数名：SeekMedia
 * 功能：定位当前播放进度
 * 参数：缺省
 * 返回值：
 *      成功返回0
 * 注意事项：无
 *******************************************/
int SeekMedia(void)
{
    int fifd = 0;
	int n = 0;
    int len = 0;
    char buffer[1024] = {0};
	char gCmdbuff[128] = {0};

	if (gMediaStat.curstat != MPLAYER_STAT_PLAY)
	{
		return 0;
	}

	fifd = open(MPLAYER_FIFO_PATH, O_RDWR);
	if (-1 == fifd)
	{
		LogWrite(LOG_ERROR, "open mplayer input fifo error, seek media failed");
		return -1;
	}

	printf("请定位:s");
	scanf("%d", &n);

	sprintf(gCmdbuff, "seek %d 2\n", n);
	write(fifd, gCmdbuff, strlen(gCmdbuff));

	close(fifd); 

    return 0;
}

/*******************************************
 * 函数名：SetMode
 * 功能：设置播放模式
 * 参数：缺省
 * 返回值：
 *      成功返回0
 * 注意事项：无
 *******************************************/
int SetMode(void)
{
    int cmd = 0;

    if (gMediaStat.curmode == MPLAYER_MODE_LOOP)
    {
        printf("always");
        gMediaStat.curmode = MPLAYER_MODE_ORDER;
        LogWrite(LOG_MESSAGE, "播放模式切换为：顺序播放\n");
        printf("当前模式：顺序播放\n");
    }
    else if (gMediaStat.curmode == MPLAYER_MODE_ORDER)
    {
        gMediaStat.curmode = MPLAYER_MODE_RANDOM;
        LogWrite(LOG_MESSAGE, "播放模式切换为：随机播放\n");
        printf("当前模式：随机播放\n");
    }
    else if (gMediaStat.curmode == MPLAYER_MODE_RANDOM)
    {
        gMediaStat.curmode = MPLAYER_MODE_LOOP;
        LogWrite(LOG_MESSAGE, "播放模式切换为：循环播放\n");
        printf("当前模式：循环播放\n");
    }
    
    printf("按任意键返回上一层");
    getchar();
    
    return 0;
}

/*******************************************
 * 函数名：Exit
 * 功能：退出程序
 * 参数：缺省
 * 返回值：
 *      成功返回0
 * 注意事项：无
 *******************************************/
int Exit(void)
{
    kill(pid, SIGKILL);

    return 0;
}
