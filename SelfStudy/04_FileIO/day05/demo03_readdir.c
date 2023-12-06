#include <dirent.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    DIR *dp = NULL;
    struct dirent *dt;

    dp = opendir("/home/gs/CodeFIle/SelfStudy/04_FileIO/day05");
    if (dp == NULL)
    {
        perror("opendir");
        return 0;
    }

    while ((dt = readdir(dp)) != NULL)
    {
        printf("%s\n", dt->d_name);
    }

    closedir(dp);
    
    return 0;
}
