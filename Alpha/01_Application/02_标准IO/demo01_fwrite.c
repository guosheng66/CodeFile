#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char buf[] = "Hello World\n";
    FILE *fp = NULL; //定义文件流指针
    
    /* 打开文件 */
    if (NULL == (fp = fopen("test.txt", "w")))
    {
        perror("fopen error");
        exit(-1);
    }

    printf("文件打开成功！\n");
    
    if (sizeof(buf) > fwrite(buf, 1, sizeof(buf), fp))
    {
        printf("fwrite error\n");
        fclose(fp);
        exit(-1);
    }

    printf("数据写入成功！\n");

    /* 关闭文件 */
    fclose(fp);
    
    return 0;
}
