#ifndef __PUBLIC_H__
#define __PUBLIC_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include <time.h>
#include <sys/wait.h>
#include <stdarg.h>

/* 日志文件记录路径 */
#define MPLAYER_LOGFILE_PATH                "./mplayer_err.log"

/* mplayer命令管道路径 */
#define MPLAYER_FIFO_PATH                   "/tmp/mplayer_fifo"

/* 媒体目录路径 */
#define MPLAYER_MEDIADIR_PATH               "/home/gs/视频"

/* 播放列表最大允许存放媒体个数 */
#define MPLAYER_MEDIALIST_MAXLEN            128

/* 日志文件路径 */
#define LOG_PATH                            "./Log"

/* 界面选项类型 */
typedef struct __menu_opt__
{
    int id;            //界面选项编号
    char content[256]; //界面选项显示字符串
    int (*pFun)(void); //界面选项对应的函数接口（操作函数指针，指向返回类型为整数的函数）
}MenuOpt_t;

/* 播放列表 */
typedef struct __media_list__
{
    char medialist[MPLAYER_MEDIALIST_MAXLEN][128]; //播放文件列表
    int CurMediaCnt;                               //当前媒体文件个数
}MediaList_t;

/* mplayer工作状态 */
typedef enum __mplayer_stat__
{
    MPLAYER_STAT_FREE,
    MPLAYER_STAT_PLAY,
    MPLAYER_STAT_PAUSE,
}MplayerStat_en;

/* mplayer播放速度 */
typedef enum __mplayer_speed__
{
    MPLAYER_SPEED_ONE,
    MPLAYER_SPEED_TWO,
    MPLAYER_SPEED_FOUR,
}MplayerSpeed_en;

/* mplayer播放模式 */
typedef enum __mplayer_mode__
{
    MPLAYER_MODE_LOOP,   //循环播放
    MPLAYER_MODE_ORDER,  //顺序播放
    MPLAYER_MODE_RANDOM, //随机播放
}MplayerMode_en;

/* 播放状态 */
typedef struct __media_stat__
{
    MplayerStat_en curstat;   //播放状态
    MplayerSpeed_en curspeed; //播放速度
    MplayerMode_en curmode;   //播放模式
    int curmedianum;          //当前播放媒体列表编号
}MediaStat_t;

extern int MenuShow(void);
extern int MenuShow(void);
extern int MenuChoose(int *pNum);
extern int ExecCommand(int cmd);

extern int IsMediaFile(char *pFileName);
extern int LoadMediaFile(const char *pDirName);
extern int ShowMediaList(void);
extern int PlayMedia(char *pMediaPath);
extern int PlayPause(void);
extern int Stop(void);
extern int PreMedia(void);
extern int NextMedia(void);
extern int AddSpeed(void);
extern int SeekMedia(void);
extern int SetMode(void);
extern int Exit(void);

#endif