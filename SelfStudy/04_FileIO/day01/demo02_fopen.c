#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp = NULL; //定义文件流指针
    int fpret = 0;   //接收文件流指针关闭后的返回值

    fp = fopen("test.txt", "r"); //以只读方式打开test.txt文件
    /* 文件打开失败打印提示信息并退出 */
    if (fp == NULL)
    {
        /* 错误提示信息，2和3等价 */
        // printf("Open file failed\n");
        // perror("fopen");
        printf("fopen: %s\n", strerror(errno));
        return -1;
    }
    else
    {
        printf("Open file success\n");
        fpret = fclose(fp);
        /* 判断是否关闭文件流指针 */
        if (fpret == 0)
        {
            printf("file close successed\n");
        }
        else
        {
            perror("flcose:"); //关闭失败打印提示信息
        }
    }
    
    return 0;
}
