#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int main(int argc, char const *argv[])
{
    psignal(SIGINT, "SIGINT描述信息");
    psignal(SIGQUIT, "SIGQUIT描述信息");
    psignal(SIGBUS, "SIGBUS描述信息");
    
    return 0;
}
