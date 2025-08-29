#include "../src_h/MyAsserts.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void MyASSert(const char *__func, const char *__FILE, int __LINE, bool condition)
{
    if(condition == false)
        printf("\n MyASSertion error!\n  In file  %s\n In function  %s\n In line  %d\n", __func__, __FILE__, __LINE__);
}

bool IsCertain(int a)
{
    if(a == NAN)
        return false;
    else
        return true;
}
