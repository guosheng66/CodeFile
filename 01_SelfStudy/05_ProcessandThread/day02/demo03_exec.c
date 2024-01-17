#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("before exec\n");
    if (execlp("ls", "ls", "-a", "./", NULL) < 0)
    {
        perror("execl");
    }
    
    return 0;
}
