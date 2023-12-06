#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t pid = 0;
    pid_t rpid = 0;
    int status = 0;

    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return 0;
    }
    else if (pid == 0)
    {
        sleep(2);
        printf("Child process:Child process will exit\n");
        exit(2);
    }
    else if (pid > 0)
    {
        sleep(3);
        waitpid(-1, &status, WNOHANG);
        printf("Child process pid:%d\n", status);
        printf("Father process:Get child status = %d\n", WEXITSTATUS(status));
    }
    
    return 0;
}

