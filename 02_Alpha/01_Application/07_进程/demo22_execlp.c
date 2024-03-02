#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	execlp("ls", "ls", "-a", "-l", NULL);
	perror("execlp error");

	return 0;
}
