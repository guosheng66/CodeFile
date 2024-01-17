#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int pid = 0;

    /* 判断传参个数 */
    if (2 > argc)
    {
        exit(-1);
    }

    /* 将传入的数字转为整形数字 */
    pid = atoi(argv[1]);
    printf("pid: %d\n", pid);

    /* 向pid指定的进程发送信号 */
    if (-1 == kill(pid, SIGINT))
    {
        perror("kill error");
        exit(-1);
    }
    
    return 0;
}
