#include <stdio.h>

int main(int argc, char const *argv[])
{
    int ch = 0;

    ch = fgetc(stdin);
    printf("%c\n", ch);
    
    return 0;
}
