#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char *arg_arr[5] = {0};
    char *env_arr[5] = {"Name=app", "AGE=25", "SEX=man", NULL};

    if (2 > argc)
    {
        exit(-1);
    }

    arg_arr[0] = argv[1];
    arg_arr[1] = "hello";
    arg_arr[2] = "world";
    arg_arr[3] = NULL;
    execve(argv[1], arg_arr, env_arr);

    perror("execve error");
    
    return 0;
}
