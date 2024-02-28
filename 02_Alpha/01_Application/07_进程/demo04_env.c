#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char const *argv[])
{
    int i = 0;

    /* 打印当前的环境变量 */
    for (i = 0; NULL != environ[i]; i++)
    {
        puts(environ[i]);
    }
    
    return 0;
}
