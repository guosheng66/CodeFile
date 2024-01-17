#include <stdio.h>

int main(int argc, char const *argv[])
{
    char buf[128] = {0};
    int year = 2023;
    int month = 10;
    int day = 1;

    int syear = 0;
    int smon = 0;
    int sday = 0;

    sprintf(buf, "%d-%d-%d", year, month, day);    //发送格式化输出到字符串中
    printf("%s\n", buf);

    sscanf(buf, "%d-%d-%d", &syear, &smon, &sday); //从字符串中读取格式化输入
    printf("%d, %d, %d\n", syear, smon, sday);  
    
    return 0;
}
