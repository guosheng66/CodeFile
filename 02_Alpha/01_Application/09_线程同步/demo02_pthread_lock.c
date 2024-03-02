#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

static pthread_mutex_t mutex;
static int g_count = 0;
static int loops = 0;

static void *new_thread_start(void *arg)
{
    int loops = *((int *)arg);
    int l_count = 0;
    int j = 0;

    for (j = 0; j < loops; j++)
    {
        pthread_mutex_lock(&mutex); //上锁

        l_count = g_count;
        l_count++;
        g_count = l_count;

        pthread_mutex_unlock(&mutex); //解锁
    }

    return (void *)0;
}

int main(int argc, char const *argv[])
{
    pthread_t tid1;
    pthread_t tid2;
    int ret = 0;

    /* 获取用户传递的参数 */
    if (2 > argc)
    {
        loops = 1000000;
    }
    else
    {
        loops = atoi(argv[1]);
    }

    /* 互斥锁初始化 */
    pthread_mutex_init(&mutex, NULL);

    /* 创建两个新线程 */
    ret = pthread_create(&tid1, NULL, new_thread_start, &loops);
    if (ret)
    {
        fprintf(stderr, "pthread_create error: %s\n", strerror(ret));
        exit(-1);
    }

    ret = pthread_create(&tid2, NULL, new_thread_start, &loops);
    if (ret)
    {
        fprintf(stderr, "pthread_create error: %s\n", strerror(ret));
        exit(-1);
    }

    /* 等待线程结束 */
    ret = pthread_join(tid1, NULL);
    if (ret)
    {
        fprintf(stderr, "pthread_join error: %s\n", strerror(ret));
        exit(-1);
    }

    ret = pthread_join(tid2, NULL);
    if (ret)
    {
        fprintf(stderr, "pthread_join error: %s\n", strerror(ret));
        exit(-1);
    }

    printf("g_count = %d\n", g_count);

    return 0;
}

