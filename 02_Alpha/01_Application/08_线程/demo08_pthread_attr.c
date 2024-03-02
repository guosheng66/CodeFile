#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

static void *new_thread_start(void *arg)
{
	puts("Hello world");

	return (void *)0;
}

int main(int argc, const char *argv[])
{
	pthread_attr_t attr;
	pthread_t tid;
	int ret = 0;

	/* 对attr对象进行初始化 */
	pthread_attr_init(&attr);

	/* 设置以分离状态启动线程 */
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	/* 创建新线程 */
	ret = pthread_create(&tid, &attr, new_thread_start, NULL);
	if (ret)
	{
		fprintf(stderr, "pthread_create error: %s\n", strerror(ret));
		exit(-1);
	}

	sleep(1);

	/* 销毁attr对象 */
	pthread_attr_destroy(&attr);

	return 0;
}
