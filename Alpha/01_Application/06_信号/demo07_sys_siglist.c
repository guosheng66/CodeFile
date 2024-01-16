/* 这个程序没跑通，是sys_siglist函数的问题，可能是新一点的系统中不包含这个函数 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv())
{
    printf("SIGINT描述信息：%s\n", sys_siglist(SIGINT));
    printf("SIGQUIT描述信息：%s\n", sys_siglist(SIGQUIT));
    printf("SIGBUS描述信息：%s\n", sys_siglist(SIGBUS));
    
    return 0;
}
