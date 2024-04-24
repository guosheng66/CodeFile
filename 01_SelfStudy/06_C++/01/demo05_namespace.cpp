#include <stdio.h>

namespace A
{
    int add(int a, int b)
    {
        return a + b;
    }
};

namespace B
{
    int add(int a, int b)
    {
        return 2 * a + b;
    }
};

using namespace A;

int main(int argc, char const *argv[])
{
    printf("%d\n", A::add(1, 2));
    printf("%d\n", B::add(1, 2));
    printf("%d\n", add(1, 2));    
    
    return 0;
}
