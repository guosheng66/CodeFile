#include "head.h"

int main(int argc, char const *argv[])
{
    char srcfilename[256] = {0};
    char dstfilename[256] = {0};
    char tmpbuff[1024] = {0};
    FILE *fsrc = NULL;
    FILE *fdst = NULL;
    size_t nsize = 0;

    printf("请输入源文件名称：");
    gets(srcfilename);
    printf("请输入目标文件名称：");
    gets(dstfilename);
    
    /* 打开源文件 */
    fsrc = fopen(srcfilename, "r");
    if (NULL == fsrc)
    {
        perror("fail to fopen");
        return -1;
    }

    /* 打开目的文件 */
    fdst = fopen(dstfilename, "w");
    if (NULL == fdst)
    {
        perror("fail to fopen");
        return -1;
    }

    while (1)
    {
        nsize = fread(tmpbuff, 1, 1024, fsrc);
        if (0 == nsize)
        {
            break;
        }
        fwrite(tmpbuff, 1, nsize, fdst);
    }

    fclose(fsrc);
    fclose(fdst);
    
    return 0;
}
