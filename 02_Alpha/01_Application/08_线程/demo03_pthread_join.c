#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

static void *new_thread_start(void *arg)
{
	printf("新线程 start\n");
	sleep(2);
	printf("新线程 end\n");
	pthread_exit((void *)10);
}

int main(void)
{
	pthread_t tid;
	void *tret = NULL;
	int ret = 0;

	ret = pthread_create(&tid, NULL, new_thread_start, NULL);
	if (ret)
	{
		fprintf(stderr, "pthread_create error : %s\n", strerror(ret));
		return -1;
	}

	ret = pthread_join(tid, &tret);
	if (ret)
	{
		fprintf(stderr, "pthread_join error: %s\n", strerror(ret));
		exit(-1);
	}

	printf("新线程终止， code = %ld\n", (long)tret); //强制类型转换
	return 0;
}
