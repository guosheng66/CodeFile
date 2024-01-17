#ifndef __LOG_H__
#define __LOG_H__

#include <stdio.h>
#include <time.h>

extern int LogInit(char *pFileName);
extern int LogWrite(char *pStr);
extern int LogDeInit(void);

#endif