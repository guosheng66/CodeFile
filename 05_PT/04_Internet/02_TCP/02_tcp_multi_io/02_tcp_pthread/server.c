#include "head.h"

void *TcpClientHandleFun(void *arg)
{
	char tmpbuff[1024] = {0};
	ssize_t nsize = 0;
	int confd = (int)arg;

	while (1)
	{
		memset(tmpbuff, 0, sizeof(tmpbuff));
		nsize = recv(confd, tmpbuff, sizeof(tmpbuff), 0);
		if (-1 == nsize)
		{
			perror("recv error");
			return NULL;
		}
		else if (0 == nsize)
		{
			fprintf(stderr, "close connection\n");
			return NULL;
		}

		sprintf(tmpbuff, "%s ---- echo", tmpbuff);

		nsize = send(confd, tmpbuff, strlen(tmpbuff), 0);
		if (-1 == nsize)
		{
			perror("send error");
			return NULL;
		}
	}

	return NULL;
}

int main(int argc, const char *argv[])
{
	int ret = 0;
	int sockfd = 0;
	int confd = 0;
	struct sockaddr_in seraddr;
	pthread_t tid;
	pthread_attr_t attr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == sockfd)
	{
		perror("fail to socket");
		return -1;
	}

	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(50000);
	seraddr.sin_addr.s_addr = inet_addr("192.168.3.108");
	ret = bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
	if (-1 == ret)
	{
		perror("bind error");
		return -1;
	}

	ret = listen(sockfd, 10);
	if (-1 == ret)
	{
		perror("listen error");
		return -1;
	}

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	while (1)
	{
		confd = accept(sockfd, NULL, NULL);
		if (-1 == confd)
		{
			perror("fail to accept");
			return -1;
		}

		pthread_create(&tid, &attr, TcpClientHandleFun, (void *)confd);
	}

	close(confd);
	close(sockfd);

	pthread_attr_destroy(&attr);

	return 0;
}
