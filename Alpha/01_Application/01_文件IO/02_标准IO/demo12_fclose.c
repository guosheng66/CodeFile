#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("Hello\n");
    printf("Hello");

    fclose(stdout); //关闭标准输出

    while (1)
    {
        sleep(1);
    }
    
    return 0;
}
