#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    const char *str_val = NULL;

    if (2 > argc)
    {
        fprintf(stderr, "Error:请输入环境变量名称\n");
        return -1;
    }

    /* 获取环境变量 */
    str_val = getenv(argv[1]);
    if (NULL == str_val)
    {
        fprintf(stderr, "Error:该环境变量不存在/getenv error\n");
        exit(-1);
    }

    /* 打印环境变量的值 */
    printf("%s=%s\n", argv[1], str_val);
    
    return 0;
}
