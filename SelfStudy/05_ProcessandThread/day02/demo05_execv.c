#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char *agv[] = {"ls", "-a", "-l", "./", NULL};

    if (execv("/bin/ls", agv) < 0)
    {
        perror("execv");
    }
    
    return 0;
}
