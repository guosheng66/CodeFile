#include <stdio.h>

int main(int argc, char const *argv[])
{
    register int a = 10;
    
    /* 在C语言中，寄存器变量（register variable）是指示编译器将变量存储在
       寄存器中的请求。寄存器变量的地址是不可取得的，因为它们可能会被编译器优
       化成不存储在内存中的值。因此，在试图获取寄存器变量的地址时会出现错误 */
    // printf("out if: a = %d %p\n", a, &a);

    printf("%d\n", a);
    
    return 0;
}
