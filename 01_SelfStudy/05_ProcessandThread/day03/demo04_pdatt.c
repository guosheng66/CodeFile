#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *func(void *arg)
{
    printf("This is child thread\n");
    sleep(25);
    pthread_exit("thread return");
}

int main(int argc, char const *argv[])
{
    pthread_t tid[100];
    void *retv = NULL;
    int i = 0;

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    for (i = 0; i < 100; i++)
    {
        pthread_create(&tid[i], &attr, func, NULL);
        // pthread_detach(tid);
    }

    while (1)
    {
        sleep(1);
    }
    
    return 0;
}
