#include <stdio.h>

int main(int argc, char const *argv[])
{
    int ch = 0;

    printf(">");

    ch = getchar();

    putchar(ch);
    putchar('\n');
    printf("ch = %d\n", ch);
    
    return 0;
}
