#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sig_handler(int sig)
{
    printf("Received signal: %d\n", sig);
}

int main(int argc, char const *argv[])
{
    struct sigaction sig = {0};
    int ret = 0;

    sig.sa_handler = sig_handler;
    sig.sa_flags = 0;
    
    ret = sigaction(SIGINT, &sig, NULL);
    if (-1 == ret)
    {
        perror("sigaction() error");
        exit(-1);
    }

    for (;;)
    {
        /* 向自身发送SIGINT信号 */
        if (0 != raise(SIGINT))
        {
            printf("raise() error\n");
            exit(-1);
        }

        sleep(3);
    }
    
    return 0;
}
