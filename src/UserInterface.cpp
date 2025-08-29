#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "../src_h/EquationSolutionFunctions.h"
#include "../src_h/UserInterface.h"
//#include "MyASSerts.h"

bool UserI()
{
    double x1 = 0;
    double x2 = 0;

    equation a;
    equation a.a = 0;
    equation a.b = 0;
    equation a.c = 0;
    equation a.x1 = &x1;
    equation a.x2 = &x2;

    printf("Enter the coefficients a, b, c separated by space:");

    NumbersScanner(&a.a, &a.b, &a.c);

    enum CountOfSolves NumberOfRoots = SolveQuadraticEquation(a);

    OutputAnswers(NumberOfRoots, *a.x1, *a.x2);
    printf("\n If want to solve one more equation print S, otherwise print N\n";
    try_again: char* one_more;
    scanf("%s", one_more);
    if(strcmp(one_more, "S"))
        return true;
    else if(strcmp(one_more, "N"))
        return false;
    else
    {
        printf("you didn't write any of the possible options, try again");
        goto try_again;
    }
}

void NumbersScanner(double* a,double* b,double* c)
{
    //MyASSert (a != NULL);
    //MyASSert (a != NULL);
    //MyASSert (a != NULL);
    while (true)
    {
        int CountOfRead = scanf("%lg %lg %lg", a, b, c);
        int isEmpty = ClearStdin();
        if (CountOfRead == 3 && isEmpty != 0)
        {
             break;
        }
        printf("\x1b[31m Invalid input format, please enter the numbers again \n \x1b[30m");
    }
}

void OutputAnswers(enum CountOfSolves NumberOfRoots, double x1, double x2)
{
    if(NumberOfRoots == One)
        printf("\x1b[33m one root: %lg \x1b[30m", x1);
    else if(NumberOfRoots == Two)
        printf("\x1b[33m two roots: x1 = %lg x2 = %lg \x1b[30m", x1, x2);
    else if(NumberOfRoots == Zero)
        printf("\x1b[33m no roots \x1b[30m");
    else if(NumberOfRoots == Infinity)
        printf("\x1b[33m infinity count of roots \x1b[30m");
}

int ClearStdin()
{
    int CountOfScanned = 1;
    int ch;
    while (true)
    {
        ch = getchar();
        if (ch == '\n' || ch == EOF)
            break;
        CountOfScanned = 0;
    }
    return CountOfScanned;
}
