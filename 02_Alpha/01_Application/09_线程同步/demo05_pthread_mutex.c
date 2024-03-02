#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

static pthread_mutex_t mutex;
static int g_avail = 2;

/* 消费者线程 */
static void *consumer_thread(void *arg)
{
    for (;;)
    {
        pthread_mutex_lock(&mutex);

        while (g_avail > 0)
        {
            g_avail--; //消费
        }

        pthread_mutex_unlock(&mutex);
    }

    return (void *)0;
}

/* 主线程（生产者） */
int main(int argc, char const *argv[])
{
    pthread_t tid;
    int ret = 0;

    /* 初始化互斥锁 */
    ret = pthread_create(&tid, NULL, consumer_thread, NULL);
    if (ret)
    {
        fprintf(stderr, "pthread_create error: %s\n", strerror(ret));
        exit(-1);
    }

    for (;;)
    {
        pthread_mutex_lock(&mutex);
        g_avail++;
        pthread_mutex_unlock;
    }

    return 0;
}
