#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    struct stat buf;
    int ret = 0;
    int i = 0;
    struct tm *t;

    ret = stat("demo02_chmod.c", &buf);  
    if (ret < 0)
    {
        perror("stat");
        return 0;
    }

    /* 判断文件类型 */
    if (S_ISREG(buf.st_mode))
    {
        printf("-");
    }
    else if (S_ISDIR(buf.st_mode))
    {
        printf("d");
    }
    else if (S_ISCHR(buf.st_mode))
    {
        printf("c");
    }
    else if (S_ISBLK(buf.st_mode))
    {
        printf("b");
    }
    else if (S_ISFIFO(buf.st_mode))
    {
        printf("p");
    }
    else if (S_ISSOCK(buf.st_mode))
    {
        printf("s");
    }

    /* 打印文件权限 */
    for (i = 8; i >= 0; i--)
    {
        if (buf.st_mode & (1 << i))
        {
            switch(i % 3)
            {
                case 2: printf("r"); break;
                case 1: printf("w"); break;
                case 0: printf("x"); break;
            }
        }
        else
        {
            printf("-");
        }
    }
    puts("");

    return 0;
}
