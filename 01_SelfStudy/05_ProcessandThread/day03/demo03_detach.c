#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *func(void *arg)
{
    pthread_detach(pthread_self());
    printf("This is child thread\n");
    sleep(25);
    pthread_exit("thread return");
}

int main(int argc, char const *argv[])
{
    pthread_t tid[100] = {0};
    void *retv = NULL;
    int i = 0;

    for (i = 0; i < 100; i++)
    {
        pthread_create(&tid[i], NULL, func, NULL);
        pthread_detach(tid);
    }

    while (1)
    {
        sleep(1);
    }
    
    return 0;
}
