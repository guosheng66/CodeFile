#include <stdio.h>

class A
{
public:
    A()
    {
        printf("construct !!!!\n");
        a = 0;
    }   
    A(int data)
    {
        a = data;
    }
    ~A()
    {
        printf("ddddddddd~~~~\n");
    }

    void show()
    {
        printf("xxxxxxxxxx\n");
    }

    void sendtata(int data)
    {
        a = data;
    }

    int getdata(void);

private:
    int a;
};

int A::getdata(void)
{
    return a;
}

int main(int argc, char const *argv[])
{
    A x(100);
    // x.a = 100;

    // x.sendtata(100);

    printf("%d\n", x.getdata());
    x.show();
    
    return 0;
}
