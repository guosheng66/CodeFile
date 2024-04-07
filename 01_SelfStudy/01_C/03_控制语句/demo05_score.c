#include <stdio.h>

int main(int argc, char const *argv[])
{
    float score = 0;

    printf("please input your score:");
    scanf("%f", &score);

    if (score < 0 || score > 100)
    {
        printf("not in [0, 100]\n");
        return 0;
    }

    if (score >= 90)
    {
        printf("A-Good\n");
    }
    
    return 0;
}
