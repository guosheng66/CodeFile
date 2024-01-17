#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int fd = 0;
    int ret = 0;
    char buf1[32] = "hello world";
    char buf2[32] = {0};
    
    fd = open("file.txt", O_RDWR | O_CREAT | O_APPEND, 0666);
    if (fd < 0)
    {
        printf("open file err\n");
        return 0;
    }
    printf("success, fd= %d\n", fd);

    ret = write(fd, buf1, strlen(buf1));
    if (ret < 0)
    {
        perror("wriet");
        goto end;
    }
    printf("write count = %d\n", ret);

    lseek(fd, 0, SEEK_SET);

    ret = read(fd, buf2, 32);
    if (ret < 0)
    {
        perror("read");
        goto end;
    }

    printf("read buf2: %s\n", buf2);

end:
    close(fd);

    return 0;
}
