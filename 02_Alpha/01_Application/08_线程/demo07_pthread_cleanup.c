#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

static void cleanup(void *arg)
{
	printf("cleanup: %s\n", (char *)arg);
}

static void *new_thread_start(void *arg)
{
	printf("新线程 -- start run\n");
	pthread_cleanup_push(cleanup, "第1次调用");
	pthread_cleanup_push(cleanup, "第2次调用");
	pthread_cleanup_push(cleanup, "第3次调用");
	
	sleep(2);
	pthread_exit((void *)0); //线程终止

	/* 与pthread_cleanup_push配对，不添加编译不会通过 */
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
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

	/* 等待新线程终止 */
	ret = pthread_join(tid, &tret);
	if (ret)
	{
		fprintf(stderr, "pthread_join error: %s\n", strerror(ret));
		exit(-1);
	}

	printf("新线程终止, code = %ld\n", (long)tret);
	
	return 0;
}
