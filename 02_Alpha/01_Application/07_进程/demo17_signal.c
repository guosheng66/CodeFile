#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//这个程序出错，好像是头文件不包含结构体sigaction

static void wait_child(int sig)
{
	/* 替子进程收尸 */
	printf("father process reccling child process\n");
	while (waitpid(-1, NULL, WNOHANG) > 0)
	{
		continue;
	}
}

int main(void)
{
    struct sigaction sig = {0};
	
	/* 为SIGCHLD信绑定处理函数 */
	sigemptyset(sig.sa_mask);
	sig.sa_handler = wait_child;
	sig.sa_flags = 0;
	if (-1 == sigaction(SIGCHLD, &sig, NULL))
	{
		perror("sigaction error");
		exit(-1);
	}
	
	/* create child process */
	switch (fork())
	{
		case -1:
			perror("fork error");
			exit(-1);
		case 0:
			/* child process */
			printf("child process %d is created\n", getpid());
			sleep(1);
			printf("child process is ended");
			_exit(0);
		default:
			/* father process */
			break;
	}

	sleep(3);

	return 0;
}
