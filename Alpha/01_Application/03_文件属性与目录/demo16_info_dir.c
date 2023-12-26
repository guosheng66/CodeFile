#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    struct dirent *dir;
    DIR *dirp;
    int ret = 0;

    /* open dir */
    dirp = opendir("../03_文件属性与目录");
    if (NULL == dirp)
    {
        perror("opendir error");
        exit(-1);
    }

    /* 循环读取目录流中的所有目录条目 */
    errno = 0;
    
    while (NULL != (dir = readdir(dirp)))
    {
        printf("%s \n", dir->d_name);
    }

    if (0 != errno)
    {
        perror("readdir errno");
        ret = -1;
        goto err;
    }
    else
    {
        printf("End of directory!\n");
    }

err:
    closedir(dirp);
    exit(ret);

    return 0;
}
