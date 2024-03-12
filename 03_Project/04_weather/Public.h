#ifndef __HEAD_H__
#define __HEAD_H__

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
#include "cJSON.h"

extern void ShowInterface(void);
extern int TcpClientCreateConnection(char *pIP, int port);
extern int ExecCommand(int cmd);
extern int TodayWeather(void);
extern int HandleData(void);
extern void MyExit(void);
extern int ChooseCity(void);
extern int FutureWeather(void);
extern int FutureHour(void);

#endif