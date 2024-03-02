#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

static void *new_thread_start(void *arg)
{
	printf("新线程 start\n");
	sleep(1);
	printf("新线程 end\n");
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t tid;
	int ret = 0;

	ret = pthread_create(&tid, NULL, new_thread_start, NULL);
	if (ret)
	{
		fprintf(stderr, "Error: %s\n", strerror(ret));
		exit(-1);
	}

	printf("主线程end\n");
	pthread_exit(NULL);

	return 0;
}
