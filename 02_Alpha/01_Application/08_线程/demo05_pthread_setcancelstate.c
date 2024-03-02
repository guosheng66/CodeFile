#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

static void *new_thread_start(void *arg)
{
	/* 线程状态设置为不可被取消 */
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);

	while (1)
	{
		printf("new process running\n");
		sleep(2);
	}

	return (void *)0;
}

int main(void)
{
	pthread_t tid;
	void *tret = NULL;
	int ret = 0;

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
		fprintf(stderr, "pthread_cancel error: %s\n", strerror(ret));
		exit(-1);
	}

	/* 等待新线程终止 */
	ret = pthread_join(tid, &tret);
	if (ret)
	{
		fprintf(stderr, "pthread_join error: %s\n", strerror(ret));
		exit(-1);
	}

	printf("新线程终止，code = %ld\n", (long)tret);

	return 0;
}

