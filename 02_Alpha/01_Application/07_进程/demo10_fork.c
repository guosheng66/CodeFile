#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    pid_t pid = 0;
    int fd = 0;
    int i = 0;

    fd = open("./test.txt", O_RDWR | O_TRUNC);
    if (0 > fd)
    {
        perror("open error");
        return -1;
    }

    pid = fork();
    switch (pid)
    {
        case -1:
            perror("fork error");
            close(fd);
            return -1;
        case 0:
            /* 子进程 */
            for (i = 0; i < 4; i++) //循环写入4次
            {
                write(fd, "1122", 4);
            }
            close(fd);
            _exit(0);
        default:
            /* 父进程 */
            for (i = 0; i < 4; i++) //循环写入4次
            {
                write(fd, "AABB", 4);
            }
            close(fd);
            exit(0);
    }

    
    return 0;
}
