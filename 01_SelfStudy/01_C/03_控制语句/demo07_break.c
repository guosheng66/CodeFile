#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    int j = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (j == 2)
            {
                break;
            }
        
            printf("i = %d, j = %d\n", i, j);
        }
        
        printf("*\n");
    }
    
    return 0;
}
