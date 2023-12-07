#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    printf("Hello\n");
    printf("Hello");

    fflush(stdout); //刷新标准输出stdio缓冲区

    while (1)
    {
        sleep(1);
    }

    return 0;
}