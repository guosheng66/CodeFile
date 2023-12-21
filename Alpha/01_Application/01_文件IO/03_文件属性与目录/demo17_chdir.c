#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char buf[128] = {0};
    char *ptr = NULL;
    int ret = 0;

    /* 获取更改前的工作目录 */
    memset(buf, 0, sizeof(buf));
    ptr = getcwd(buf, sizeof(buf));
    if (NULL == ptr)
    {
        perror("getcwd error");
        exit(-1);
    }

    printf("Before the change: %s\n", buf);
    
    /* 更改进程当前的工作目录 */
    ret = chdir("../02_标准IO");
    if (-1 == ret)
    {
        perror("chdir error");
        exit(-1);
    }

    /* 获取更改后的工作目录 */
    memset(buf, 0, sizeof(buf));
    ptr = getcwd(buf, sizeof(buf));
    if (NULL == ptr)
    {
        perror("getcwd error");
        exit(-1);
    }

    printf("After the change: %s\n", buf);
    
    return 0;
}
