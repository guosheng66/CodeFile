#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("Hello World\n");
    printf("Hello World");
    
    while (1)
    {
        sleep(1);
    }

    return 0;
}

/*
只打印了第一个printf中的内容，因为标准输出默认采用行缓冲，第二个
printf中的内容还缓存在stdio缓冲区中，需要等待一个换行符才可输出到终端
*/