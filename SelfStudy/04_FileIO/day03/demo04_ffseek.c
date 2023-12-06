#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp = NULL;
    
    fp = fopen("file.txt", "w");
    if (fp == NULL)
    {
        perror("fopen");
        return 0;
    }

    fwrite("abcdef", 6, 1, fp);
    printf("current fp = %d\n", (int)ftell(fp));

    fseek(fp, 3, SEEK_CUR);
    printf("current fp = %d\n", (int)ftell(fp));
    rewind(fp); //设置文件位置为给定流 stream 的文件的开头

    printf("After rewind fp = %d\n", (int)ftell(fp));
    fwrite("location", 7, 1, fp);

    fclose(fp);
    
    return 0;
}
