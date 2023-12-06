#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int fd = 0;
    int ret = 0;

    fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd  < 0)
    {
        printf("open file err\n");
        return 0;
    }

    printf("success, fd = %d\n", fd);

    ret = close(fd);
    if (ret < 0)
    {
        printf("close failed\n");
    }

    ret = close(fd);
    printf("ret = %d\n", ret);
    
    return 0;
}
