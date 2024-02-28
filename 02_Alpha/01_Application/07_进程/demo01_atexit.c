#include <stdio.h>
#include <stdlib.h>

static void Bye(void)
{
    puts("Good bye");
}

int main(int argc, char const *argv[])
{
    if (atexit(Bye))
    {
        fprintf(stderr, "can't see exit function\n");
        exit(-1);
    }
    
    return 0;
}
