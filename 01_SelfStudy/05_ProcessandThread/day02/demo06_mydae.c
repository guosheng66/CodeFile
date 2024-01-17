#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    pid_t pid = 0;
    
    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return 0;
    }
    else if (pid > 0)
    {
        exit(0); //父进程退出，这将使程序变成守护进程
    }
    printf("I'm a deamon\n");
    /* 打印进程的会话ID，进程ID和进程组ID */
    printf("sid = %d, pid = %d, pgid = %d\n", getsid(getpid()), getpid(), getpgid(getpid()));
    
    /* 创建新的会话，并使子进程成为会话领导 */
    if (setsid() < 0)
    {
        perror("setsid");
        exit(0);
    }

    printf("after:\nsid = %d, pid = %d, pgid = %d\n", getsid(getpid()), getpid(), getpgid(getpid()));

    chdir("/"); //改变工作目录到根目录

    /* 设置文件权限掩码为0, 以确保守护进程可以创建文件 */
    if (umask(0) < 0)
    {
        perror("unmask");
        exit(0);
    }

    close(0); //关闭标准输入流
    close(1); //关闭标准输出流
    close(2); //关闭标准错误流
    printf("after close\n");
    /* 守护进程可以在后台运行了，可以添加其他需要的人物 */

    sleep(100); //睡眠100s，模拟守护进程在后台运行

    return 0;
}
