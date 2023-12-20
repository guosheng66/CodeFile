#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    mode_t old_mask;

    old_mask = umask(0003);
    printf("old mask: %04o\n", old_mask);
    
    return 0;
}
