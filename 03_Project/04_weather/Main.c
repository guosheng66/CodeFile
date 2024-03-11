#include "Public.h"

int main(int argc, char const *argv[])
{
    int cmd = 0;
    
    while (1)
    {
        ShowInterface();
        printf("Please enter instructions:");
        scanf("%d", &cmd);
        TcpClientCreateConnection("103.205.5.228", 80);
        ExecCommand(cmd);
    }   
    
    return 0;
}
