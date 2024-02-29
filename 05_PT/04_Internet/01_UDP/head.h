#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

typedef enum type
{
    MSG_TYPE_FILENAME,
    MSG_TYPE_CONTENT,
    MSG_TYPE_EXIT,
}type_t;

typedef struct message
{
    type_t type;     //消息类型（文件名、文件内容、退出）
    char text[1024]; //消息内容
    int len;         //消息长度
}message_t;

#endif