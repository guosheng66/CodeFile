#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOC_MEM_SIZE (1 * 1024 * 1024)

int main(int argc, char const *argv[])
{
    char *base = NULL;

    /* 申请堆内存 */
    base = (char *)malloc(MALLOC_MEM_SIZE);
    if (NULL == base)
    {
        perror("malloc() error");
        return -1;
    }

    /* 初始化申请到的堆内存 */
    memset(base, 0, MALLOC_MEM_SIZE);
    
    free(base);
    
    return 0;
}
