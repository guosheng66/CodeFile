#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <arpa/inet.h>
#include <fcntl.h>

typedef struct sockaddr* (SA);

int main(int aegc, char *argv[])
{
	int cond = 0;
	int srcfd = 0;
	int ret = 0;
	struct sockaddr_in ser;
	char buf[1204] = {0};
	int rd_ret = 0;

	cond = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == cond)
	{
		perror("socket error");
		exit(-1);
	}

	bzero(&ser, sizeof(ser));
	ser.sin_family = AF_INET;
	ser.sin_port = htons(50000);
        ser.sin_addr.s_addr = inet_addr("192.168.3.108");
	       
	ret = connect(cond, (SA)&ser, sizeof(ser));
	if (-1 == ret)
	{
		perror("connect error");
		exit(-1);
	}

	srcfd = open("1.png", O_RDONLY);
	if (-1 == srcfd)
	{
		perror("open error");
		exit(-1);
	}

	while (1)
	{
		rd_ret = read(srcfd, buf, sizeof(buf));
		if (rd_ret  <= 0)
		{
			break;
		}

		send(cond, buf, rd_ret, 0);
		recv(cond, buf, sizeof(buf), 0);
	}


	return 0;
}
