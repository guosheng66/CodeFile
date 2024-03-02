#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

static void *new_thread_start(void *arg)
{
    printf("新线程：进程ID--%d, 线程ID：%lu\n", getpid(), pthread_self());

    return (void *) 0;
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    int ret = 0;

    ret = pthread_create(&tid, NULL, new_thread_start, NULL);
    if (ret)
    {
        fprintf(stderr, "Error: %s\n", strerror(ret));
        exit(-1);
    }

    printf("主线程：进程ID：--%d, 线程ID：%lu\n", getpid(), pthread_self());

    sleep(1);

    return 0;
}
