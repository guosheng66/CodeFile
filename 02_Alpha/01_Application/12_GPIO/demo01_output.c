#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

static char gpio_path[100];

static int goio_config(const char *attr, const char *val)
{
    char file_path[100] = {0};
    int len = 0;
    int fd = 0;

    sprintf(file_path, "%s%s", gpio_path, attr);
    if (0 > (fd = open(file_path, O_WRONLY)))
    {
        perror("open() error");
        return fd;
    }

    len = strlen(val);
    if (len != write(fd, val, len))
    {
        perror("write() error");
        close(fd);
        return -1;
    }

    clsoe(fd);

    return 0;
}

int main(int argc, char const *argv[])
{
    int fd = 0;
    int len = 0;

    if (3 != argc)
    {
        fprintf(stderr, "usage:%s <gpio><value>\n", argv[0]);
        exit(-1);
    }

    sprintf(gpio_path, "sys/class/gpio/gpio%s", argv[1]);   //判断指定编号的GPIO是否导出
    
    /* 如果目录不存在，则需要导出 */
    if (access(gpio_path, F_OK))
    {
        if (0 > (fd = open("sys/class/gpio/export", O_WRONLY)))
        {
            perror("open() error");
            close(fd);
            exit(-1);
        }

        close(fd);        
    }

    /* 设置为输出模式 */
    if (gpio_config("direction", "out"))
    {
        exit(-1);
    }

    /* 极性设置 */
    if (gpio_config("active_low", "0"))
    {
        exit(-1);
    }

    /* 控制GPIO输出高低电平 */
    if (gpio_config("value", argv[2]))
    {
        exit(-1);
    }

    return 0;
}
