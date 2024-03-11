#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int fd = 0;
    char buf[1024] = {0};
    char *date = NULL;
    char *week = NULL;
    char *name = NULL;
    char *temp = NULL;
    char *wea = NULL;
    char *end = NULL;

    fd = open("data", O_RDONLY);
    if (-1 == fd)
    {
        perror("open error");
        exit(-1);
    }
    read(fd, buf, sizeof(buf));

    date = strstr(buf, "days");
    week = strstr(date, "week");
    name = strstr(week, "citynm");
    temp = strstr(name, "temperature");
    wea = strstr(temp, "weather");

    date += 7;
    week += 7;
    name += 9;
    temp += 14;
    wea += 10;

    end = index(date,'"');
    *end = '\0';

    end = index(week,'"');
    *end = '\0';
    end = index(name,'"');
    *end = '\0';
    end = index(temp,'"');
    *end = '\0';
    end = index(wea,'"');
    *end = '\0';
    printf("%s:%s:%s:%s:%s\n",date,week,name,temp,wea);

    close(fd);

    return 0;
}
