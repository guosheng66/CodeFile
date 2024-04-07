#include <stdio.h>

int main(int argc, char const *argv[])
{
    int y = 0;
    int m = 0;
    int d = 0;

    printf(">");
    scanf("%c%c%c", &y, &m, &d);
    // scanf("%4d%2d%2d", &y, &m, &d);

    printf("y: %d   m: %d   d: %d\n", y, m, d);
    
    return 0;
}
