#include "head.h"

int main(int argc, char const *argv[])
{
	int sockfd = 0;
	int ret = 0;
	int cnt = 0;
	ssize_t nsize = 0;
	char tmpbuff[1024] = {"hello world"};
	struct sockaddr_in seraddr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == sockfd)
	{
		perror("socket error");
		return -1;
	}

	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(50000);
	seraddr.sin_addr.s_addr = inet_addr("192.168.3.108");
	ret = connect(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
	if (-1 == ret)
	{
		perror("fail to connect");
		return -1;
	}

	while (1)
	{
		sprintf(tmpbuff, "hello world ---- %d", cnt);
		cnt++;
		nsize = send(sockfd, tmpbuff, strlen(tmpbuff), 0);
		if (-1 == nsize)
		{
			perror("fail to send");
			return -1;
		}

		memset(tmpbuff, 0, sizeof(tmpbuff));
		nsize = recv(sockfd, tmpbuff, sizeof(tmpbuff), 0);
		if (-1 == nsize)
		{
			perror("recv error");
			return -1;
		}

		printf("RECV: %s\n", tmpbuff);
	}
	
	close(sockfd);

	return 0;
}
