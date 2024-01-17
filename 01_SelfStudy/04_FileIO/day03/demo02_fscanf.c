#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp = NULL;
    int year = 0;
    int mon = 0;
    int day = 0;

    fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return 0;
    }

    fscanf(fp, "%d-%d-%d", &year, &mon, &day);

    printf("%d-%d-%d\n", year, mon, day);
    
    return 0;
}
