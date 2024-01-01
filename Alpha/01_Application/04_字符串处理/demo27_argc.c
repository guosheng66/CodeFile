#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int i = 0;

    printf("Num of parameters: %d\n", argc);
    for (i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    
    return 0;
}
