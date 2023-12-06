#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char buffer[1024] = {0}; //存储文件内容
    int fd1 = 0;
    int fd2 = 0;
    int ret = 0;

    /* 打开src文件 */
    fd1 = open("./src.txt", O_RDONLY);
    if (-1 == fd1)
    {
        printf("Error: open src_file failed\n");
        return -1;
    }

    /* 新建dest文件并打开 */
    fd2 = open("./dest.txt", O_WRONLY | O_CREAT, 0664);
    if (-1 == fd2)
    {
        printf("Error: open dest_file failed\n");
        ret = -1;
        goto err1;
    }

    /* 将src文件读写位置移动到偏移文件头500个字节处 */
    ret = lseek(fd1, 500, SEEK_SET);
    if (-1 == ret)
    {
        perror("fail to lseek");
        goto err1;
    }

    /* 读取src_file文件数据，大小1KByte */
    ret = read(fd1, buffer, sizeof(buffer));
    if (-1 == ret)
    {
        printf("Error: read src_file filed!\n");
        goto err1;
    }

    /* 将dest文件读写位置移动到文件头 */
    ret = lseek(fd2, 0, SEEK_SET);
    if (-1 == ret)
    {
        goto err2;
    }

    /* 将buffer中的数据写入到dest文件中，大小1KByte */
    ret = write(fd2, buffer, sizeof(buffer));
    if (-1 == ret)
    {
        printf("Error: write dest_file failed\n");
        goto err2;
    }

    printf("OK: test successful\n");
    ret = 0;

err1:
    close(fd1);

err2:
    close(fd2);
    
    return 0;
}
