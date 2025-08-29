#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "../src_h/MyAsserts.h"
#include "../src_h/EquationSolutionFunctions.h"

bool is_zero(double a)
{
    if(fabs(a-0.0) <= EPS)
        return true;
    else
        return false;
}

enum CountOfSolves SolveQuadraticEquation(equation a)
{
    MyASSert (IsCertain(a.a));
    MyASSert (IsCertain(a.b));
    MyASSert (IsCertain(a.c));
    MyASSert (a.x1 != NULL);
    MyASSert (a.x2 != NULL);
    if(is_zero(a.a))
        return linear_equation(a);
    else
        return quadratic_equation(a);
}



enum CountOfSolves linear_equation(equation a)
{
    *(a.x1) = *(a.x2) = (-a.c)/a.b;
    if(a.b==0)
        return Infinity;
    else
        return One;
}

enum CountOfSolves quadratic_equation (equation a)
{
    double d = a.b*a.b - 4*a.a*a.c;
    if(d < 0)
        return Zero;
    else
    {
        if(is_zero(d))
        {
            *(a.x1) = *(a.x2) = (-a.b)/(2*a.a);
            return One;
        }
        else
        {
            *(a.x1) = (-a.b + sqrt(d))/(2*a.a);
            *(a.x2) = (-a.b - sqrt(d))/(2*a.a);
            return Two;
        }
    }
}
