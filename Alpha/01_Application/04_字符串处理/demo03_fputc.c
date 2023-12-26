#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    fputc('A', stdout);
    fputc('A', stdout);
    fputc('A', stdout);
    fputc('A', stdout);
    fputc('\n', stdout);
    
    return 0;
}
