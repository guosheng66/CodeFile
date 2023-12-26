#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[128] = {0};
    FILE *fp = NULL;

    /* 打开文件 */
    fp = fopen("test.file", "r");
    if (NULL == fp)
    {
        perror("fopen error");
        return -1;
    }

    /* 从文件中读取字符串 */
    fgets(str, sizeof(str), fp);
    printf("%s", str);

    /* 关闭文件 */
    fclose(fp);
    
    return 0;
}
