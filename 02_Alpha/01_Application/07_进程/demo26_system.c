#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv[])
{
	int ret = 0;

	if (2 > argc)
	{
		exit(-1);
	}

	ret = system(argv[1]);
	if (-1 == ret)
	{
		// perror("system error");
		fputs("system error", stderr);
	}
	else
	{
		if (WIFEXITED(ret) && (127 == WEXITSTATUS(ret)))
		{
			fputs("could not invoke shell,\n", stderr);
		}
	}

	return 0;
}
