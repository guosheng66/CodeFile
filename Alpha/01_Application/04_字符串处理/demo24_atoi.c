#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("atoi: %d\n", atoi("500"));
    printf("atol: %ld\n", atol("500"));
    printf("atoll: %lld\n", atoll("500"));  

    return 0;
}
