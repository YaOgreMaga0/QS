#include "../src_h/EquationSolutionFunctions.h"
#include "../src_h/MyAsserts.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! checks the condition for the correct launch of the function
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
void ASS(const char *func, const char *FILE, int LINE, bool condition)
{
    if(!condition)
        printf(RED "\n MyASSertion error!\n  In file  %s\n In function  %s\n In line  %d\n" BLACK, func, FILE, LINE);
}
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! checks a number for finiteness
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
bool IsCertain(int a)
{
    if(a == NAN)
        return false;
    else
        return true;
}
