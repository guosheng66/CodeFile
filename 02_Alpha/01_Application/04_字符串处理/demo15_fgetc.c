#include <stdio.h>

int main(int argc, char const *argv[])
{
    int ch = 0;
    FILE *fp = NULL;

    /* 打开文件 */
    fp = fopen("./test.file", "r");
    if (NULL == fp)
    {
        perror("fopen error");
        return -1;
    }

    /* 从文件中输入一个字符 */
    ch = fgetc(fp);
    printf("%c\n", ch);
    
    /* 关闭文件 */
    fclose(fp);
    
    return 0;
}
