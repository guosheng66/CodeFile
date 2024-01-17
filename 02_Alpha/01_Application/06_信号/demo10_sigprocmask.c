#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sig_handler(int sig)
{
    printf("信号处理函数：...\n");

}
int main(int argc, char const *argv[])
{
    struct sigaction sig = {0};
    sigset_t sig_set;

    /* 注册信号处理函数 */
    sig.sa_handler = sig_handler;
    sig.sa_flags = 0;

    if (-1 == sigaction(SIGINT, &sig, NULL))
    {
        perror("sigaction() error");
        exit(-1);
    }

    /* 信号集初始化 */
    sigemptyset(&sig_set);
    sigaddset(&sig_set, SIGINT);

    /* 向信号掩码中添加信号 */
    if (-1 == sigprocmask(SIG_BLOCK,&sig_set, NULL))
    {
        exit(-1);
    }

    raise(SIGINT); //向自己发送信号

    sleep(2);
    printf("休眠结束\n");

    /* 从信号掩码中溢出添加的信号 */
    if (-1 == sigprocmask(SIG_UNBLOCK, &sig_set, NULL))
    {
        perror("sigprocmask() error");
        exit(-1);
    }

    return 0;
}
