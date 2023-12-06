#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *TestOfThread(void *arg)
{
    printf("This is a thread test, pid = %d, tid = %lu\n", getpid(), pthread_self());
    //return NULL;
    printf("input arg = %d\n", (int)arg);
    pthread_exit(NULL);
    printf("after pthread exit\n");
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    int ret = 0;
    int arg = 5;

    ret = pthread_create(&tid, NULL, TestOfThread, (void *)arg);

    printf("This is main thread, tid = %lu\n", tid);
    sleep(1);

    return 0;
}
