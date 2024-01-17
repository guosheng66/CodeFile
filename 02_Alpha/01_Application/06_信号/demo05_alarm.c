#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sig_handler(int sig)
{
    puts("Alarm timeout");
    exit(0);
}

int main(int argc, char const *argv[])
{
    struct sigaction sig = {0};
    int sec = 0;

    /* 检验参数个数 */
    if (2 > argc)
    {
        exit(-1);
    }

    /* 为SIGALARM信号绑定处理函数 */
    sig.sa_handler = sig_handler;
    sig.sa_flags = 0;

    if (-1 == sigaction(SIGALRM, &sig, NULL))
    {
        perror("sigaction() error");
        exit(-1);
    }

    /* 启动alarm定时器 */
    sec = atoi(argv[1]);
    printf("定时时长：%d s\n", sec);
    alarm(sec);

    for (;;)
    {
        sleep(1);
    }
    
    return 0;
}
