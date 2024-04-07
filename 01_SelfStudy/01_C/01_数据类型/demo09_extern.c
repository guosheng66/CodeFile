#include <stdio.h>

extern int gNum1;
extern int gNum2;

int main(int argc, char const *argv[])
{
    /* 使用外部内容的时候记得将包含该内容的c文件一起编译 */
    printf("%d\n", gNum1);
    printf("%d\n", gNum2);
    
    return 0;
}
