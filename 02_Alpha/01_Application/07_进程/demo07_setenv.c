#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (3 > argc)
    {
        fprintf(stderr, "Error:传入name value\n");
        return -1;
    }

    /* 添加环境变量 */
    if (setenv(argv[1], argv[2], 0))
    {
        perror("setenv error");
        return -1;
    }
    
    return 0;
}