#include <stdio.h>

class A;

class B
{
public:
    void printA(A &x);
};

class A
{
public:
    A()
    {
        x = 100;
    }

    // friend class B;
    friend void B::printA(A &x);

private:
    int x;
};

void B::printA(A &x)
{
    printf("%d\n", x.x);
}

int main(int argc, char const *argv[])
{
    A a;
    // printf("%d\n", a.x);

    B b;
    b.printA(a);
    
    return 0;
}
