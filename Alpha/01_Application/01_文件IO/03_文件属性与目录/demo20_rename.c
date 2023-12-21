#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int ret = 0;

    ret = rename("./test01.file", "test02.file");
    if (-1 == ret)
    {
        perror("rename error");
        return -1;
    }

    return 0;
}
