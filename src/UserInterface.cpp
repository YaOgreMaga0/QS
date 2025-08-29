#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "../src_h/EquationSolutionFunctions.h"
#include "../src_h/UserInterface.h"
//#include "MyASSerts.h"

void NumbersScanner(double* a, double* b, double* c);
void OutputAnswers(enum CountOfSolves NumberOfRoots, double x1, double x2);
int ClearStdin();

void UserI()
{
    double a = 0, b = 0, c = 0;

    double x1 = 0;
    double x2 = 0;

    printf("Enter the coefficients a, b, c separated by space:");

    NumbersScanner(&a, &b, &c);

    enum CountOfSolves NumberOfRoots = SolveQuadraticEquation(a, b, c, &x1, &x2);

    OutputAnswers(NumberOfRoots, x1, x2);
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
