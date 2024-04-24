#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main(int argc, char const *argv[])
{
#if 0
    char *p = NULL;

    p = (char *)malloc(10);
    strcpy(p, "hello");
    
    printf("p: %s\n", p);

    free(p);
#endif

    int *pint = NULL;
    pint = new int;

    *pint = 100;
    printf("*pint = %d\n", *pint);

    delete pint;

    char *p = new char[10];

    strcpy(p, "hello");
    printf("p: %s\n", p);
    
    delete [] p;
    
    return 0;
}
