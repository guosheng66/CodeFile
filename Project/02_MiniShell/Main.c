#include "Terminal.h"
#include "Command.h"

int main(int argc, char const *argv[])
{
    char CommandBuff[1024] = {0}; 
    
    while (1)
    {
        ShowTerminal();
        GetTerminal(CommandBuff, sizeof(CommandBuff));
        
    }
    
    return 0;
}
