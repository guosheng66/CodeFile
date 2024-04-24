#include <stdio.h>
#include <string.h>

class A
{
public:
    A()
    {
        printf("A()\n");
        p = new char[10];
        strcpy(p, "hello");

        printf("p: %s\n", p);
        printf("p: %s\n", this->p);
    }

    A(const A &x)
    {
        printf("A(const A &x)\n");
        p = new char[10];
        strcpy(p, x.p);
    }

    ~A()
    {
        printf("~A()\n");
        delete [] p;
    }

private:
    char *p;
};

int main(int argc, char const *argv[])
{
    A x;
    
    A y = x;

    return 0;
}
