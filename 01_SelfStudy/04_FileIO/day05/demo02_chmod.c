#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    int ret = 0;

    ret = chmod("file.txt", 0777);
    if (ret < 0)
    {
        perror("chmod");
        return 0;
    }
    
    return 0;
}
