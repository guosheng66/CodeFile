#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

static void sig_handler(int sig)
{
    printf("接收到信号\n");
}

int main(int argc, char const *argv[])
{
    struct sigaction sig = {0};
    sigset_t wait_mask;

    /* 初始化信号集 */
    sigemptyset(&wait_mask);

    /* 设置信号处理方式 */
    sig.sa_handler = sig_handler;
    sig.sa_flags = 0;
    if (-1 == sigaction(SIGUSR1, &sig, NULL))
    {
        perror("sigaction error");
        exit(-1);
    }
    
    switch (fork())
    {
        case -1:
            perror("fork error");
            exit(-1);
        case 0:
            /* 子进程 */
            printf("子进程开始执行\n");
            printf("子进程：child\n");
            sleep(2);
            kill(getppid(), SIGUSR1); //发送信号给父进程，唤醒它
            _exit(0);
        default:
            /* 父进程 */
            if (-1 != sigsuspend(&wait_mask)) //挂起，阻塞
            {
                exit(-1);
            }
            printf("父进程开始执行\n");
            printf("父进程:father\n");
            exit(0);
    }
    
    
    return 0;
}
