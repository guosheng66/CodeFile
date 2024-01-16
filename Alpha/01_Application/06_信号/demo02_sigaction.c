#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void sig_handler(int sig)
{
    printf("Received signal:%d\n", sig);
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

    /* 死循环 */
    for (;;)
    {}
    
    return 0;
}
