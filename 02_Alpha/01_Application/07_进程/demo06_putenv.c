#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (2 > argc)
    {
        fprintf(stderr, "Error:传入name=value\n");
        return -1;
    }

    /* 添加或修改环境变量 */
    if (putenv(argv[1]))
    {
        perror("putenv error");
        return -1;
    }
    
    return 0;
}
