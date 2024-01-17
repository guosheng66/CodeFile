#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    /* 将标准输出设置为无缓冲模式 */
    if (setvbuf(stdout, NULL, _IONBF, 0))
    {
        perror("setvbuf error");
        exit(0);
    }

    printf("Hello World\n");
    printf("Hello World");

    while (1)
    {
        sleep(1);
    }
    
    return 0;
}
