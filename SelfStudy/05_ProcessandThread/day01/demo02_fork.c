#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    pid_t pid = 0;

    // printf("before fork\n");
    pid = fork(); //创建进程
    
    if (pid > 0)
    {
        printf("This is father process\n");
        printf("pid = %d\n", (int)pid);
        // printf("father process(after fork)\n");
        while (1)
        {
            sleep(1);
            printf("father sleep\n");
        }
    }
    else if (pid == 0)
    {
        printf("This is child process\n");
        printf("pid = %d\n", (int)pid);
        // printf("child after fork\n");
        while (1)
        {
            sleep(1);
            printf("child sleep\n");
        }
    }
    else if (pid < 0)
    {
        perror("fork");
        return 0;
    }

    return 0;
}
