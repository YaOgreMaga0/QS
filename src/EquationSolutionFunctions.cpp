#include <stdio.h>
#include <assert.h>
#include <math.h>
//#include "MyASSerts.h"
#include "../src_h/EquationSolutionFunctions.h"



enum CountOfSolves SolveQuadraticEquation(equation a)
{
    //MyASSert (IsCertain(a));
    //MyASSert (IsCertain(b));
    //MyASSert (IsCertain(c));
    //assert (x1 != NULL);
    //assert (x2 != NULL);
    if(is_zero(a.a))
        return linear_equation(a);
    else
        return quadratic_equation(a);
}


bool is_zero(double a)
{
    if(fabs(a-0.0) <= EPS)
        return true;
    else
        return false;
}

enum linear_equation(struct a)
{
    *a.x1 = *a.x2 = (-c)/b;
    if(*a.x1 == NAN)
        return Infinity;
    else
        return One;
}

enum quadratic_equation (struct a)
{
    double d = b*b - 4*a*c;
    if(d<0)
        return Zero;
    else
    {
        if(is_zero(d))
        {
            *x1 = *x2 = (-b)/(2*a);
            return One;
        }
        else
        {
            *x1 = (-b/2a) + sqrt(d);
            *x2 = (-b/2a) - sqrt(d);
        }
    }
}
