#include "../src_h/MyAsserts.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void ASS(const char *func, const char *FILE, int LINE, bool condition)
{
    if(!condition)
        printf("\n MyASSertion error!\n  In file  %s\n In function  %s\n In line  %d\n", func, FILE, LINE);
}

bool IsCertain(int a)
{
    if(a == NAN)
        return false;
    else
        return true;
}
