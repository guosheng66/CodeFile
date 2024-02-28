#include "head.h"

int main(int argc, char const *argv[])
{
    char srcfilename[256] = {0};
    char dstfilename[256] = {0};
    char tmpbuff[1024] = {0};
    size_t nsize = 0;
    int fsrc = 0;
    int fdst = 0;

    printf("请输入源文件名称：");
    gets(srcfilename);
    printf("请输入目标文件名称：");
    gets(dstfilename);

    /* 打开源文件 */
    fsrc = open(srcfilename, O_RDONLY);
    if (-1 == fsrc)
    {
        perror("fail to open");
        return -1;
    }

    /* 打开目的文件 */
    fdst = open(dstfilename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (-1 == fdst)
    {
        perror("fail to open");
        return -1;
    }

    while (1)
    {
        nsize = read(fsrc, tmpbuff, sizeof(tmpbuff));
        if (nsize <= 0)
        {
            break;
        }
        write(fdst, tmpbuff, nsize);
    }

    close(fsrc);
    close(fdst);
    
    return 0;
}
