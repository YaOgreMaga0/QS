#include <stdio.h>
#include <math.h>
#include "../src_h/EquationSolutionFunctions.h"
#include "../src_h/SolverTests.h"

const int CountOfTests = 10;
void SolverT();

void SolverT()
{
    int CountOfFailedTests = 0, i = 0;
    equation a;
    a.a = 0;
    a.b = 0;
    a.c = 0;
    int nRoots = 0;
    FILE *fp = fopen("../Tests.txt", "r");
    while (fscanf(fp,"%lg%lg%lg%d", &(a.a), &(a.b), &(a.c),&nRoots ) != EOF)
        {
            double x1 = 0.0, x2 = 0.0;
            a.x1 = &x1;
            a.x2 = &x2;
            int NumberOfRoots = SolveQuadraticEquation(a);
            if(NumberOfRoots != nRoots)
            {
                printf(RED "the number of roots in the test %d is not determined correctly \n" BLACK, i+1);
                CountOfFailedTests++;
            }
            else
            {
                if(NumberOfRoots == 1 || NumberOfRoots == 2)
                {
                    if(fabsf((*a.x1)*(*a.x1)*a.a + (*a.x2)*a.b + a.c - 0) >= EPS || fabsf(((*a.x2)*(*a.x2)*a.a + (*a.x2)*a.b +a.c)- 0) >= EPS)
                    {
                        printf(RED "large calculation error in the test number %d \n" BLACK, i+1);
                        CountOfFailedTests++;
                    }
                }
        }
        i++;
    }
    fclose(fp);
    printf(GREEN "%d / %d %s", CountOfTests - CountOfFailedTests, CountOfTests, "tests passed successfully" BLACK);
}
