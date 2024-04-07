#include <stdio.h>

int main(int argc, char const *argv[])
{
    char s[] = "hello world";

    printf("%15s\n", s);
    printf("%15.5s\n", s);
    printf("%2.5s\n", s);
    printf("%.5s\n", s);
    
    return 0;
}
