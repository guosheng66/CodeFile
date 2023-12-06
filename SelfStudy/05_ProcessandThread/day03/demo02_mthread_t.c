#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *TestThread(void *arg)
{
    printf("This is a thread test, pid = %d, tid = %d\n\n", getpid(), pthread_self());
    // return NULL;
    printf("This is %d thread.\n", (int)arg);
    // pthread_exit(NULL);
    while (1)
    {
        slepp(1);
    }
    printf("after pthread exit.\n");
}

int main(int argc, char const *argv[])
{
    pthread_t tid[5] = {0};
    int ret = 0;
    int arg = 5;
    int i = 0;

    for (i = 0; i < 5; i++)
    {
        ret = pthread_create(&tid[i], NULL, TestThread, (void *)i);
        // sleep(1);
        printf("This is main thread, tid = %lu\n", tid[i]);
    }
    
    while (1)
    {
        sleep(1);
    }
    
    return 0;
}
