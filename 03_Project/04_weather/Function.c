#include "Public.h"

char gTmpBuff[10240] = {0};
char gCjsonData[10240] = {0};
char gCityNm[64] = {"北京"};

/************************************************
 * 函数名：ShowMenu
 * 函数功能：打印操作界面
 * 参数：缺省
 * 返回值：无
 * 注意事项：无
 ************************************************/
void ShowInterface(void)
{
    printf("+===========================+\n");
    printf("|1.today                    |\n");
    printf("|2.future day               |\n");
    printf("|3.future hour              |\n");
    printf("|4.choose city              |\n");
    printf("|5.clear screen             |\n");
    printf("|6.exit                     |\n");
    printf("+===========================+\n");
}

/************************************************
 * 函数名：ExecCommand
 * 函数功能：执行相应函数功能
 * 参数：
 *      int cmd:接收用户输入的命令
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ************************************************/
int ExecCommand(int cmd)
{
    switch (cmd)
    {
        case 1: TodayWeather();  break;
        case 2: FutureWeather(); break;
        case 3: FutureHour(); break;
        case 4: ChooseCity();    break;
        case 5: system("clear"); break;
        case 6: MyExit();        break;
        default: printf("提示：输入错误，请重新输入\n"); break;
    }
    
    return 0;
}

/************************************************
 * 函数名：TcpClientCreateConnection
 * 函数功能：建立客户端与服务器连接，接收数据
 * 参数：
 *      char *pIP:服务器IP地址
 *      int port:服务器端口
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ************************************************/
int TcpClientCreateConnection(char *pIP, int port)
{
    int sockfd = 0;
    int ret = 0;
    int cnt = 0;
    char gTmpBuff[10240] = {0};  
    char *http_cmd[6] = {NULL};
    FILE *fp = NULL;
    struct sockaddr_in ser;
    
    http_cmd[0] = (char*)malloc(1000 * sizeof(char)); //由于http_cmd[0]为NULL，无法直接使用sprintf函数对其进行赋值操作
                                                      //在使用sprintf函数之前，需要先为http_cmd[0]分配内存空间
   	sprintf(http_cmd[0], "GET /?app=weather.realtime&cityNm=%s&ag=today,futureDay,lifeIndex,futureHour&appkey=10003&sign=b59bc3ef6191eb9f747dd4e83c99f2a4&format=json HTTP/1.1\r\n", gCityNm);
    http_cmd[1]="Host: api.k780.com\r\n";
    http_cmd[2]="Connection: keep-alive\r\n";
    http_cmd[3]="User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.87 Safari/537.36 SE 2.X MetaSr 1.0\r\n";
    http_cmd[4]="Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9\r\n";
    http_cmd[5]="Accept-Language: zh-CN,zh;q=0.9\r\n\r\n";


    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sockfd)
    {
        perror("socket error");
        return -1;
    }

    bzero(&ser, sizeof(ser));
    ser.sin_family = AF_INET;
    ser.sin_port = htons(port);
    ser.sin_addr.s_addr = inet_addr(pIP);

    ret = connect(sockfd, (struct sockaddr *)&ser, sizeof(ser));
    if (-1 == ret)
    {
        perror("connect error");
        return -1;
    }

    for (cnt = 0; cnt < 6; cnt++)
    {
        send(sockfd, http_cmd[cnt], strlen(http_cmd[cnt]), 0);
    }

    recv(sockfd, gTmpBuff, sizeof(gTmpBuff), 0);

    fp = fopen("weather.txt", "w");
	if (NULL == fp)
	{
		perror("fopen error");
		exit(-1);
	}
	fputs(gTmpBuff, fp);
    
    fclose(fp);
    close(sockfd);

    return 0;
}

/************************************************
 * 函数名：HandleData
 * 函数功能：处理得到的数据（只保留json格式数据）
 * 参数：
 *      缺省
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ************************************************/
int HandleData(void)
{
    int fd = 0;
    int cnt = 0;
    char *pSrc = NULL;
    char *pDst = NULL;

    fd = open("weather.txt", O_RDONLY);
    if (-1 == fd)
    {
        perror("open error");
        return -1;
    }
    read(fd, gTmpBuff, sizeof(gTmpBuff));

    pSrc = gTmpBuff;
    while (*pSrc != '{')
    {
        pSrc++;
        cnt++;
    }

    memmove(gCjsonData, gTmpBuff + cnt, strlen(gTmpBuff) - cnt + 1);
    
    pDst = gCjsonData;
    while (*pDst != '\0')
    {
        pDst++;
    }

    while (*pDst != '}')
    {
        *pDst = '\0';
        pDst--;
    }

    return 0;
}

/************************************************
 * 函数名：TodayWeather
 * 函数功能：获取当日天气
 * 参数：
 *      缺省
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ************************************************/
int TodayWeather(void)
{
    cJSON *cJsonData = NULL;
    cJSON *AllData = NULL;
    cJSON *TodayData = NULL;
    char *wtNm1 = NULL;
    char *wtNm2 = NULL;
    char *wtTemp1 = NULL;
    char *wtTemp2 = NULL;

    HandleData();

    cJsonData = cJSON_Parse(gCjsonData);
    AllData = cJSON_GetObjectItem(cJsonData, "result");
    TodayData = cJSON_GetObjectItem(AllData, "today");

    wtTemp1 = cJSON_GetObjectItem(TodayData, "wtTemp1")->valuestring;
    wtTemp2 = cJSON_GetObjectItem(TodayData, "wtTemp2")->valuestring;
    printf("%s: 当日天气:温度: %s ~ %s°C    ", gCityNm ,wtTemp2, wtTemp1);
    wtNm1 = cJSON_GetObjectItem(TodayData, "wtNm1")->valuestring;
    printf("白天天气: %s    ", wtNm1);
    wtNm2 = cJSON_GetObjectItem(TodayData, "wtNm2")->valuestring;
    printf("夜晚天气: %s\n", wtNm2); 

    return 0;
}

/************************************************
 * 函数名：FutureHour
 * 函数功能：获取未来几个小时的天气
 * 参数：
 *      缺省
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ************************************************/
int FutureHour(void)
{
    int cnt = 0;
    int i = 0;
    cJSON *cJsonData = NULL;
    cJSON *AllData = NULL;
    cJSON *FutureHour = NULL;
    cJSON *Data = NULL; //存储对象数组中的子对象
    char *dateYmdh = NULL;
    char *wtTemp = NULL;
    char *wtWindNm = NULL;

    HandleData();

    cJsonData = cJSON_Parse(gCjsonData);
    AllData = cJSON_GetObjectItem(cJsonData, "result");
    FutureHour = cJSON_GetObjectItem(AllData, "futureHour");
    cnt = cJSON_GetArraySize(FutureHour);   
    
    Data = FutureHour->child;
    dateYmdh = cJSON_GetObjectItem(Data, "dateYmdh")->valuestring;
    wtTemp = cJSON_GetObjectItem(Data, "wtTemp")->valuestring;
    wtWindNm = cJSON_GetObjectItem(Data, "wtWindNm")->valuestring;
    printf("%s: %s: 温度: %s    风向: %s\n", gCityNm, dateYmdh, wtTemp, wtWindNm);

    Data = Data->next;
    dateYmdh = cJSON_GetObjectItem(Data, "dateYmdh")->valuestring;
    wtTemp = cJSON_GetObjectItem(Data, "wtTemp")->valuestring;
    wtWindNm = cJSON_GetObjectItem(Data, "wtWindNm")->valuestring;
    printf("%s: %s: 温度: %s    风向: %s\n", gCityNm, dateYmdh, wtTemp, wtWindNm);

    Data = Data->next;
    dateYmdh = cJSON_GetObjectItem(Data, "dateYmdh")->valuestring;
    wtTemp = cJSON_GetObjectItem(Data, "wtTemp")->valuestring;
    wtWindNm = cJSON_GetObjectItem(Data, "wtWindNm")->valuestring;
    printf("%s: %s: 温度: %s    风向: %s\n", gCityNm, dateYmdh, wtTemp, wtWindNm);

    Data = Data->next;
    dateYmdh = cJSON_GetObjectItem(Data, "dateYmdh")->valuestring;
    wtTemp = cJSON_GetObjectItem(Data, "wtTemp")->valuestring;
    wtWindNm = cJSON_GetObjectItem(Data, "wtWindNm")->valuestring;
    printf("%s: %s: 温度: %s    风向: %s\n", gCityNm, dateYmdh, wtTemp, wtWindNm);

    Data = Data->next;
    dateYmdh = cJSON_GetObjectItem(Data, "dateYmdh")->valuestring;
    wtTemp = cJSON_GetObjectItem(Data, "wtTemp")->valuestring;
    wtWindNm = cJSON_GetObjectItem(Data, "wtWindNm")->valuestring;
    printf("%s: %s: 温度: %s    风向: %s\n", gCityNm, dateYmdh, wtTemp, wtWindNm);

    return 0;
}

/************************************************
 * 函数名：FutureWeather
 * 函数功能：获取未来几天的天气
 * 参数：
 *      缺省
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ************************************************/
int FutureWeather(void)
{
    int cnt = 0;
    int i = 0;
    cJSON *cJsonData = NULL;
    cJSON *AllData = NULL;
    cJSON *FutureData = NULL;
    cJSON *Data = NULL; //存储对象数组中的子对象
    char *dateYmd = NULL;
    char *wtNm1 = NULL;
    char *wtNm2 = NULL;
    char *wtTemp1 = NULL;
    char *wtTemp2 = NULL;

    HandleData();

    cJsonData = cJSON_Parse(gCjsonData);
    AllData = cJSON_GetObjectItem(cJsonData, "result");
    FutureData = cJSON_GetObjectItem(AllData, "futureday");
    cnt = cJSON_GetArraySize(FutureData);   
    
    Data = FutureData->child;
    dateYmd = cJSON_GetObjectItem(Data, "dateYmd")->valuestring;
    wtTemp1 = cJSON_GetObjectItem(Data, "wtTemp1")->valuestring;
    wtTemp2 = cJSON_GetObjectItem(Data, "wtTemp2")->valuestring;
    printf("%s: %s: 温度: %s ~ %s\n", gCityNm ,dateYmd, wtTemp1, wtTemp2);

    Data = Data->next;
    dateYmd = cJSON_GetObjectItem(Data, "dateYmd")->valuestring;
    wtTemp1 = cJSON_GetObjectItem(Data, "wtTemp1")->valuestring;
    wtTemp2 = cJSON_GetObjectItem(Data, "wtTemp2")->valuestring;
    printf("%s: %s: 温度: %s ~ %s\n", gCityNm ,dateYmd, wtTemp1, wtTemp2);

    Data = Data->next;
    dateYmd = cJSON_GetObjectItem(Data, "dateYmd")->valuestring;
    wtTemp1 = cJSON_GetObjectItem(Data, "wtTemp1")->valuestring;
    wtTemp2 = cJSON_GetObjectItem(Data, "wtTemp2")->valuestring;
    printf("%s: %s: 温度: %s ~ %s\n", gCityNm ,dateYmd, wtTemp1, wtTemp2);

    Data = Data->next;
    dateYmd = cJSON_GetObjectItem(Data, "dateYmd")->valuestring;
    wtTemp1 = cJSON_GetObjectItem(Data, "wtTemp1")->valuestring;
    wtTemp2 = cJSON_GetObjectItem(Data, "wtTemp2")->valuestring;
    printf("%s: %s: 温度: %s ~ %s\n", gCityNm ,dateYmd, wtTemp1, wtTemp2);

    return 0;
}

/************************************************
 * 函数名：ChooseCity
 * 函数功能：选择要查询天气的城市
 * 参数：
 *      缺省
 * 返回值：
 *      成功返回0
 *      失败返回-1
 * 注意事项：无
 ************************************************/
int ChooseCity(void)
{
    printf("please select a city:");
    scanf("%s", gCityNm);

    return 0;
}

/********************************************
 * 函数名:MyExit
 * 功能:退出minishell
 * 参数:
 * 		缺省
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
void MyExit(void)
{
	exit(0);
}