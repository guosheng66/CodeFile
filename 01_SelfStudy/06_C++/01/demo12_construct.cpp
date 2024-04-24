#include <stdio.h>

class A
{
public:
    A()
    {
        printf("A()\n");
    }
    A(int data)
    {
        printf("A(int data)\n");
    }
    ~A()
    {
        printf("A~~~~~~~~~~~~~~~\n");
    }
};

int main(int argc, char const *argv[])
{
    //called when new object is created!

    A *p = new A(1000);
    A x;
    A m(100);
    A y = 10;
    A z = y;
        
    return 0;
}
