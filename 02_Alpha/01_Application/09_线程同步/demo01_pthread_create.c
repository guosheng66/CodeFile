#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

static int g_count = 0;
static int loops;

static void *new_thread_start(void *arg)
{
    int loops = *((int*)arg);
    int l_cnt = 0;
    int j = 0;

    for (j = 0; j < loops; j++)
    {
        l_cnt = g_count;
        l_cnt++;
        g_count = l_cnt;
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
        loops = 1000000; //没有传递参数默认为100万次
    }
    else
    {
        loops = atoi(argv[1]);
    }

    /* 创建2个新线程 */
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
    }

    ret = pthread_join(tid2, NULL);
    if (ret)
    {
        fprintf(stderr, "pthread_join error: %s\n", strerror(ret));
    }

    printf("g_count = %d\n", g_count);

    return 0;
}
