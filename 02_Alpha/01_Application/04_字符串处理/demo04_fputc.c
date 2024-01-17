#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fp = NULL;

    /* 创建一个文件 */
    fp = fopen("test.file", "a");
    if (NULL == fp)
    {
        perror("fopen error");
        return -1;
    }

    /* 将字符输入到文件 */
    fputc('A', fp);
    fputc('A', fp);
    fputc('A', fp);
    fputc('A', fp);
    fputc('\n', fp);
    
    fclose(fp);

    return 0;
}
