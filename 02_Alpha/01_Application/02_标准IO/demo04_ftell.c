/* 通过ftell和fseek计算文件的大小 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fp = NULL;
    int ret = 0;

    /* 打开文件 */
    if (NULL == (fp = fopen("test.txt", "r")))
    {
        perror("fopen error");
        exit(-1);
    }
    printf("文件打开成功!\n");

    /* 将读写位置移动到文件末尾 */
    if (0 > fseek(fp, 0, SEEK_END))
    {
        perror("fseek error");
        fclose(fp);
        exit(-1);
    }

    /* 获取当前位置偏移量 */
    if (0 > (ret = ftell(fp)))
    {
        perror("ftell error");
        fclose(fp);
        exit(-1);
    }

    printf("文件大小：%d个字节\n", ret);

    fclose(fp);
    
    return 0;
}
