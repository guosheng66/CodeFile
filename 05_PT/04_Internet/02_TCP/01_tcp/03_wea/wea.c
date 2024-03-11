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

typedef struct sockaddr *(SA);

int main(int argc, const char *argv[])
{
	int cond = 0;
	int ret = 0;
	int i = 0;
	char buf[1024] = {0};
	FILE *fp = NULL;
	char *http_cmd[6] = {NULL};
	struct sockaddr_in ser;

	http_cmd[0]="GET /?app=weather.today&cityNm=西安&appkey=68279&sign=608b0c36e2c762db677415e6e4d29bca&format=json HTTP/1.1\r\n";
    http_cmd[1]="Host: api.k780.com\r\n";
    http_cmd[2]="Connection: keep-alive\r\n";
    http_cmd[3]="User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.87 Safari/537.36 SE 2.X MetaSr 1.0\r\n";
    http_cmd[4]="Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9\r\n";
    http_cmd[5]="Accept-Language: zh-CN,zh;q=0.9\r\n\r\n";

	cond =socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == cond)
	{
		perror("socket error");
		exit(-1);
	}

	bzero(&ser, sizeof(ser));
	ser.sin_family = AF_INET;
	ser.sin_port = htons(80);
	ser.sin_addr.s_addr = inet_addr("103.205.5.228");

	ret = connect(cond, (SA)&ser, sizeof(ser));
	if (-1 == ret)
	{
		perror("connect error");
		exit(-1);
	}

	for (i = 0; i < 6; i++)
	{
		send(cond, http_cmd[i], strlen(http_cmd[i]), 0);
	}

	recv(cond, buf, sizeof(buf), 0);
	printf("%s", buf);
	
	fp = fopen("data", "w");
	if (NULL == fp)
	{
		perror("fopen error");
		exit(-1);
	}

	fputs(buf, fp);

	fflush(stdout);
	fclose(fp);
	close(cond);

	return 0;
}
