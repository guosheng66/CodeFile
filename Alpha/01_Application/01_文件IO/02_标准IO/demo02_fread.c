#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char buf[48] = {0};
    FILE *fp = NULL;
    int size = 0;

    /* 打开文件 */
    if (NULL == (fp = fopen("test.txt", "r")))
    {
        perror("fopen error");
        exit(-1);
    }

    printf("文件打开成功\n");
    
    /* 读取数据 */
    if (12 > (size = fread(buf, 1, 12, fp)))
    {
        /* 使用ferror判断是否发生错误 */
        if (ferror(fp))
        {
            printf("fread error");
            fclose(fp);
            exit(-1);
        }
    }

    printf("成功读取%d个字节数据: %s", size, buf);

    /* 关闭文件 */
    fclose(fp);
    
    return 0;
}
