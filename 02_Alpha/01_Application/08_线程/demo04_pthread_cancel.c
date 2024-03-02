#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

static void *new_thread_start(void *arg)
{
	printf("新线程--running\n");

	for (;;)
	{
		sleep(1);
	}

	return (void *)0;
}

int main(void)
{
	pthread_t tid = 0;
	int ret = 0;
	void *tret;
	
	/* 创建新线程 */
	ret = pthread_create(&tid, NULL, new_thread_start, NULL);
	if (ret)
	{
		fprintf(stderr, "pthread_create error: %s\n", strerror(ret));
		exit(-1);
	}

	sleep(1);
	
	/* 向新线程发送取消请求 */
	ret = pthread_cancel(tid);
	if (ret)
	{
		fprintf(stderr, "pthread_cancel: %s\n", strerror(ret));
		exit(-1);
	}

	printf("新线程终止，code = %ld\n", (long)tret);

	return 0;
}
