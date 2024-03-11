#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <strings.h>
#include <string.h>
#include <string.h>
#include <fcntl.h>

typedef struct sockaddr *(SA);

int main(int argc, char *argv[])
{
	int listfd = 0;
	int ret = 0;
	int cond = 0;
	int dstfd = 0;
	char buf[1024] = {0};
	int rec_ret = 0;
	socklen_t len = 0;
	struct sockaddr_in ser;
	struct sockaddr_in clt;

	listfd = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == listfd)
	{
		perror("socket error");
		exit(-1);
	}

	bzero(&ser, sizeof(ser));
	bzero(&clt, sizeof(clt));

	ser.sin_family = AF_INET;
	ser.sin_port = htons(50000);
	ser.sin_addr.s_addr = INADDR_ANY;

	ret = bind(listfd, (SA)&ser, sizeof(ser));
	if (-1 == ret)
	{
		perror("bind error");
		exit(-1);
	}
	listen(listfd, 3);

	len = sizeof(clt);

	cond = accept(listfd, (SA)&clt, &len);
	if (-1 == cond)
	{
		perror("accept error");
		exit(-1);
	}

	dstfd = open("2.png", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (-1 == dstfd)
	{
		perror("open error");
		exit(-1);
	}

	while (1)
	{
		rec_ret = recv(cond, buf, sizeof(buf), 0);
		if (rec_ret <= 0)
		{
			break;
		}

		write(dstfd, buf, rec_ret);
		bzero(buf, sizeof(buf));
		strcpy(buf, "go on");
		send(cond, buf, strlen(buf), 0);
	}

	close(cond);
	close(listfd);

	return 0;
}
