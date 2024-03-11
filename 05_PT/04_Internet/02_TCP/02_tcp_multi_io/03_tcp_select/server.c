#include "head.h"

int TcpHandleFun(int confd)
{
	char tmpbuff[1024] = {0};
	ssize_t nsize = 0;

	memset(tmpbuff, 0, sizeof(tmpbuff));
	nsize = recv(confd, tmpbuff, sizeof(tmpbuff), 0);
	if (-1 == nsize)
	{
		perror("recv error");
		return -1;
	}
	else if (0 == nsize)
	{
		return 0;
	}

	sprintf(tmpbuff, "%s ---- echo", tmpbuff);

	nsize = send(confd, tmpbuff, strlen(tmpbuff), 0);
	if (-1 == nsize)
	{
		return -1;
	}

	return nsize;
}

int TcpServerCreateListenSocket(char *pIP, int port)
{
	int sockfd = 0;
	struct sockaddr_in seraddr;
	int ret = 0;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == sockfd)
	{
		perror("socket error");
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

	return sockfd;
}

int main(int argc, char const *argv[])
{
	int sockfd = 0;
	int maxfd = 0;
	fd_set rdfds;
	fd_set tmpfds;
	int ret = 0;
	int confd = 0;
	int i = 0;

	sockfd = TcpServerCreateListenSocket("192.168.3.108", 50000);
	if (-1 == sockfd)
	{
		fprintf(stderr, "create tcp server socket failed\n");
		return -1;
	}

	maxfd = sockfd;
	FD_ZERO(&rdfds);
	FD_SET(sockfd, &rdfds);
	tmpfds = rdfds;

	while (1)
	{
		tmpfds = rdfds;

		/* 监听集合 */
		ret = select(maxfd + 1, &tmpfds, NULL, NULL, NULL);
		if (-1 == ret)
		{
			perror("select error");
			return -1;
		}

		/* 判断是否sockfd产生事件 */
		if (FD_ISSET(sockfd, &tmpfds))
		{
			confd = accept(sockfd, NULL, NULL);
			if (-1 == confd)
			{
				FD_CLR(sockfd, &rdfds);
				close(sockfd);
				continue;
			}

			/* 将新建立的连接加入监听集合 */
			printf("新客户端建立连接\n");
			FD_SET(confd, &rdfds);
			maxfd = confd > maxfd ? confd : maxfd;
		}

		/* 检测所有的已建立的连接中是否产生事件 */
		for (i = sockfd + 1; i <= maxfd; i++)
		{
			if (FD_ISSET(i, &tmpfds))
			{
				ret = TcpHandleFun(i);
				if (-1 == ret)
				{
					printf("客户端一场断开\n");
					FD_CLR(i, &rdfds);
					close(i);
					continue;
				}
				else if (0 == ret)
				{
					printf("客户端断开\n");
					FD_CLR(i, &rdfds);
					close(i);
					continue;
				}
			}
		}
	}

	return 0;
}
