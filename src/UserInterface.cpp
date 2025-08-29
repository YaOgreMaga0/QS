#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "../src_h/EquationSolutionFunctions.h"
#include "../src_h/UserInterface.h"
#include "../src_h/MyAsserts.h"

int UserI()
{
    double x1 = 0;
    double x2 = 0;

    equation a;
    a.a = 0;
    a.b = 0;
    a.c = 0;
    a.x1 = &x1;
    a.x2 = &x2;

    printf("Enter the coefficients a, b, c separated by space:");

    NumbersScanner(&a.a, &a.b, &a.c);

    enum CountOfSolves NumberOfRoots = SolveQuadraticEquation(a);

    OutputAnswers(NumberOfRoots, *a.x1, *a.x2);
}

void NumbersScanner(double* a,double* b,double* c)
{
    MyASSert (a != NULL);
    MyASSert (a != NULL);
    MyASSert (a != NULL);
    while (true)
    {
        int CountOfRead = scanf("%lg %lg %lg", a, b, c);
        int isEmpty = ClearStdin();
        if (CountOfRead == 3 && isEmpty != 0)
        {
             break;
        }
        printf(RED" Invalid input format, please enter the numbers again \n" BLACK);
    }
}

void OutputAnswers(enum CountOfSolves NumberOfRoots, double x1, double x2)
{
    if(NumberOfRoots == One)
        printf(YELLOW"one root: %lg" BLACK, x1);
    else if(NumberOfRoots == Two)
        printf(YELLOW" two roots: x1 = %lg x2 = %lg" BLACK, x1, x2);
    else if(NumberOfRoots == Zero)
        printf(YELLOW" no roots" BLACK);
    else if(NumberOfRoots == Infinity)
        printf(YELLOW" infinity count of roots" BLACK);
}

int ClearStdin()
{
    int CountOfScanned = 1;
    int ch= '\n';
    while (true)
    {
        ch = getchar();
        if (ch == '\n' || ch == EOF)
            break;
        CountOfScanned = 0;
    }
    return CountOfScanned;
}
