#include <stdio.h>

void debug(const char *ptr = "-------------------")
{
    printf("%s\n", ptr);
}

int main(int argc, char const *argv[])
{

    debug();
    debug();
    debug("hello ");
    debug("world");
    debug();
    debug();
    
    return 0;
}
