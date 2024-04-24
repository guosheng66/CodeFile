#include <stdio.h>
#include <string.h>

#if 0
int intcmp(int a, int b)
{
    return (a - b);
}

int scmp(const char *str1, const char *str2)
{
    return strcmp(str1, str2);
}
#endif

int cmp(int a, int b)
{
    return (a - b);
}

int cmp(const char *str1, const char *str2)
{
    return strcmp(str1, str2);
}


int main(int argc, char const *argv[])
{

    // printf("int: %d\n", intcmp(1, 2));
    // printf("str: %d\n", scmp("aabb", "aaaa"));
    
    printf("int: %d\n", cmp(1, 2));
    printf("str: %d\n", cmp("aaabb", "bbbb"));

    return 0;
}
