#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp = NULL;
    char rd_buf[128] = {0};
    char wr_buf[] ="hello\n";
    int ret = 0;

    /* 打开文件 */
    fp = fopen("test.txt", "w+");
    if (fp == NULL)
    {
        perror("fopen error");
        exit(-1);
    }
    printf("文件打开成功！\n");
    
    /* 写文件 */
    if (sizeof(wr_buf) > fwrite(wr_buf, 1, sizeof(wr_buf), fp))
    {
        printf("fwrite error\n");
        fclose(fp);
        exit(-1);
    }
    printf("数据写入成功\n");

    /* 将读写位置移动到文件头部 */
    if (0 > fseek(fp, 0, SEEK_SET))
    {
        perror("fseek error");
        fclose(fp);
        exit(-1);
    }

    /* 读文件 */
    if (sizeof(wr_buf) > (ret = fread(rd_buf, 1, sizeof(wr_buf), fp)))
    {
        printf("fread error\n");
        fclose(fp);
        exit(-1);
    }

    printf("成功读取%d个字节数据：%s", ret, rd_buf);

    fclose(fp);
    
    return 0;
}
