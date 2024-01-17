#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    pid_t pid = 0;
    int i = 0;

    for (i = 0; i < 5; i++)
    {
        pid = fork();
        if (pid < 0)
        {
            perror("fork");
            return 0;
        }
        else if (pid == 0)
        {
            printf("Child process %d: %d", ++i, getpid());
            // sleep(5);
            break;
        }
        else
        {
            printf("Father process:%d\n", getpid());
            sleep(1);
        }
    }

    sleep(100);
    
    return 0;
}
