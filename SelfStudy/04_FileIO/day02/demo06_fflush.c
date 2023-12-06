#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    FILE *fp = NULL;
    
    printf("abcdefg");
    fflush(stdout);

    fp = fopen("file.txt", "w");
    if (fp == NULL)
    {
        perror("fopen");
        return 0;
    }

    fwrite("abcdef", 7, 1, fp);

    printf("abcdefg");
    fflush(stdout);

    while (1)
    {
        sleep(1);
    }
    
    return 0;
}
