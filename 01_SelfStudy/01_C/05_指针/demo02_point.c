#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char ch1[] = "hello world!";
    char ch2[] = "hello world!";
    char *p = NULL;

    p = ch1;

    if (isalpha(*p))
    {
        if (isupper(*p))
        {
            *p = tolower(*p);
        }
        else
        {
            *p = toupper(*p);
        }
    }

    printf("%p %s\n", p, p);
    p = ch2;
    printf("%p %s\n", p, p);
    
    return 0;
}
