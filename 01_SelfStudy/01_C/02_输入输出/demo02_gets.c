#include <stdio.h>

int main(int argc, char const *argv[])
{
    char s[5];

    // scanf("%s", s);
    gets(s);
    printf("s: %s\n", s);
    puts(s);
    
    return 0;
}
