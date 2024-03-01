#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	/* create child process */
	switch (fork())
	{
		case -1:
			perror("fork error");
			exit(-1);
		case 0:
			/* child process */
			printf("child process %d is created, father process is %d\n", getpid(), getppid());
			sleep(3);
			printf("father process is %d\n", getppid());
			_exit(0);
		default:
			/* father process */
			break;
	}

	sleep(1);
	printf("father process ended\n");

	return 0;
}
