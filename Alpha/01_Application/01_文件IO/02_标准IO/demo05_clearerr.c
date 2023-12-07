#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fp = NULL;
    char buf[24] = {0};

    /* 打开文件 */
    if (NULL == (fp = fopen("test.txt", "r")))
    {
        perror("fopen error");
        exit(-1);
    }
    printf("文件打开成功\n");

    /* 将读写位置移动到末尾 */
    if (0 > fseek(fp, 0, SEEK_END))
    {
        perror("fseek error");
        fclose(fp);
        exit(-1);
    }

    /* 读文件 */
    if (10 > fread(buf, 1, 10, fp))
    {
        if (feof(fp))
        {
            printf("end-of-file 标志被设置，已到文件末尾！\n");
        }
        clearerr(fp); //清除标志
    }

    fclose(fp);

    return 0;
}
