#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp = NULL;      //创建文件流指针
    char *ret = NULL;
    int retn = 0;         //定义变量用来接收函数返回值
    char buff[128] = {0}; //创建数组用来存储从流中获取的数据
    char buff1[128] = {0}; //创建数组用来存储从流中获取的数据

    fp = fopen("file.txt", "a+"); //以追加读写方式打开file.txt文件
    if (fp == NULL)
    {
        perror("fopen");
        return 0;
    }

    /* 从文件流fp中读取5个字符到buff中(包括最后的空字符) */
    ret = fgets(buff, 5, fp);
    if (ret == NULL)
    {
        perror("fgets");
        fclose(fp);
        return 0;
    }

    printf("buff: %s\n", buff);

    /* 向file.txt文件中写入内容 */
    retn = fputs("hello world\n", fp);
    if (retn == -1)
    {
        perror("fputs");
        return 0;
    }

    fclose(fp);

    return 0;
}
