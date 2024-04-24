#include <stdio.h>

class A
{
public:
    A(int a = 50, int data = 1000):b{data}
    {
        this->a = a;
        printf("AAAAAAAAAAAAAAAAAA\n");
    }

    ~A()
    {
        printf("~~~~~~~~~~~~~~~~~~\n");
    }

    void show(void) const
    {
        printf("b = %d\n", b);
        printf("a = %d\n", a);
    }

private:
    int a;
    const int b;
};

int main(int argc, char const *argv[])
{
    A x(10);
    x.show();

    A y(100);
    y.show();
    
    A z;
    z.show();

    return 0;
}
