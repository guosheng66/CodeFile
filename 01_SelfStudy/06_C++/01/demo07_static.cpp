#include <stdio.h>

class A
{
public:
    static void func(void)
    {
        printf("xxxxxxxxxxxxxxxxxxxx\n");
    }

    static int data;
};

int A::data = 10;

int main(int argc, char const *argv[])
{
    A a;

    a.func();
    A::func();

    A x;
    x.data = 100;
    printf("x.data =  %d\n", x.data);

    A::data = 1000;
    printf("x.data = %d\n", x.data);
  
    return 0;
}
