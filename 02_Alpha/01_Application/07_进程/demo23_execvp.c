#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *arg_arr[5];

	arg_arr[0] = "ls";
	arg_arr[1] = "-a";
	arg_arr[2] = "-l";
	arg_arr[3] = NULL;
	execvp("ls", arg_arr);

	perror("execvp error");

	return 0;
}
