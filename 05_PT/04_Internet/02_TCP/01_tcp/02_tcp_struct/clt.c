#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <strings.h>
#include <string.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct sockaddr *(SA);
typedef struct
{
	char filename[512];
	char buf[1024];
	int rd_ret;
	int size;
}MSG;

int main(int argc, const char *argv[])
{
	int cond = 0;
	int ret = 0;
	int srcfd = 0;
	struct stat st;
	struct sockaddr_in ser;
	MSG msg;

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
	if (srcfd == -1)
	{
		perror("open error");
		exit(-1);
	}
	
	bzero(&msg, sizeof(msg));
	strcpy(msg.filename, "2.png");

	stat(msg.filename, &st);
	msg.size = st.st_size;
	printf("%lu\n", st.st_size);
	while (1)
	{
		bzero(msg.buf, sizeof(msg.buf));
		msg.rd_ret = read(srcfd, &msg.buf, sizeof(msg.buf));
		send(cond, &msg, sizeof(msg), 0);
		if (msg.rd_ret <= 0)
		{
			break;
		}

		recv(cond, &msg, sizeof(msg), 0);
	}

	close(cond);
	close(srcfd);

	return 0;
}
