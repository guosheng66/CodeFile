#ifndef __ARR_H__
#define __ARR_H__

#include <stdio.h>

class ARR
{
public:
    ARR():tail(0)
    {
        tail = 0;
    }

    void addtail(int data);
    void show(void);

    friend void rev(ARR &arr);

private:
    int data[100];
    int tail;
};

#endif