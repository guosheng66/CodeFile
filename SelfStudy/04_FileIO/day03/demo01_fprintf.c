#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp = NULL;
    int year = 2023;
    int month = 10;
    int day = 1;

    fp = fopen("file.txt", "w+");
    if (fp == NULL)
    {
        perror("fopen");
        return 0;
    }

    fprintf(fp, "%d-%d-%d\n", year, month, day);
    
    return 0;
}
