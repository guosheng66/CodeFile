#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    pid_t pid = 0;

    printf("before exec\n");
    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return -1;
    }
    else if (pid == 0)
    {
        if (execl("/bin/ls", "-a", "-l", "./", NULL) < 0)
        {
            perror("execl");
        }
    }

    printf("after execl\n");
    
    return 0;
}
