#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <strings.h>
#include <string.h>
#include <fcntl.h>

typedef struct sockaddr * (SA);
typedef struct
{
	char filename[512];
	char buf[1024];
	int rd_ret;
	int size;
}MSG;

int main(int argc, const char *argv[])
{
	int listfd = 0;
	int ret = 0;
	int cond = 0;
	int first_flag = 0;
	int size = 0;
	int dstfd = 0;
	int rec_ret = 0;
	int currnt_size = 0;
	struct sockaddr_in clt;
	struct sockaddr_in ser;
	socklen_t len;
	MSG msg;

	listfd = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == listfd)
	{
		perror("socket error");
		exit(-1);
	}

	bzero(&ser, sizeof(ser)); //memset(&ser, 0, sizeof(ser));
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

	bzero(&msg, sizeof(msg));
	while (1)
	{
		rec_ret = recv(cond, &msg, sizeof(msg), 0);
		if (rec_ret <= 0)
		{
			break;
		}
		if (0 == first_flag)
		{
			//dstfd = open(msg.filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
			dstfd = open("2.png", O_WRONLY | O_CREAT | O_TRUNC, 0666);
			if (-1 == dstfd)
			{
				perror("open error");
				exit(-1);
			}
			size = msg.size;
			first_flag = 1;
		}

		write(dstfd, msg.buf, msg.rd_ret);
		currnt_size += msg.rd_ret;
		printf("%d/%d\n", currnt_size, size);
		bzero(&msg, sizeof(msg));
		strcpy(msg.buf, "go on");
		send(cond, &msg, sizeof(msg), 0);
	}	

	close(cond);
	close(listfd);
	close(dstfd);

	return 0;
}
