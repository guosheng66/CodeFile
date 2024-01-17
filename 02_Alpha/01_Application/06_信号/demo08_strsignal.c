#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int main(int argc, char const *argv[])
{
    printf("SIGINT描述信息：%s\n", strsignal(SIGINT));
    printf("SIGQUIT描述信息：%s\n", strsignal(SIGQUIT));
    printf("SIGBUS描述信息：%s\n", strsignal(SIGBUS));
    printf("编号为1000的描述信息：%s\n", strsignal(1000));
    
    return 0;
}
