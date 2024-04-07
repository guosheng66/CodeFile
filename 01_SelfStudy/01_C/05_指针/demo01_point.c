#include <stdio.h>

int main(int argc, char const *argv[])
{
    char ch = 'A';
    char *p = NULL;

    p = &ch;
    printf("%c %c", ch, *p);
    
    return 0;
}
