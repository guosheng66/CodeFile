/*
 * 通过 access 函数检查文件是否存在，若存在、则继续检查
 * 执行进程的用户对该文件是否有读、写、执行权限。
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int ret = 0;

    /* 检查文件是否存在 */
    ret = access("MY_FILE", F_OK);
    if (-1 == ret)
    {
        printf("%s: file does not exist.\n", "MY_FILE");
    }

    /* 检查权限 */
    ret = access("test.file", R_OK);
    if (!ret)
    {
        printf("Read permission: Yes\n");
    }
    else
    {
        printf("Read Permission: No\n");
    }

    ret = access("test.file", W_OK);
    if (!ret)
    {
        printf("Write permission: Yes\n");
    }
    else
    {
        printf("Write Permission: No\n");
    }

        ret = access("test.file", X_OK);
    if (!ret)
    {
        printf("Execution permission: Yes\n");
    }
    else
    {
        printf("Execution Permission: No\n");
    }
    
    return 0;
}
