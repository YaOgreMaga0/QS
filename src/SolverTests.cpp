#include <stdio.h>
#include <math.h>
#include "../src_h/SolverTests.h"
#include "../src_h/EquationSolutionFunctions.h"

const int CountOfTests = 10;
void SolverT();

void SolverT()
{
    int CountOfFailedTests = 0;
    test TestsSet[CountOfTests] = {{0, 5, 10, 1},
                                  {1, 0, -9, 2},
                                  {0, 0, 7, 3},
                                  {0, -2, 4, 1},
                                  {1, 4, 4, 1},
                                  {0, 0, -3, 3},
                                  {0, 1, -1, 1},
                                  {1, 2, 2, 0},
                                  {0, 1, 0, 1},
                                  {0, 0, 0, 3}};
    for (int i = 0; i < CountOfTests; i++)
        {
            double x1 = 0.0, x2 = 0.0;
            equation a;
            a.a = TestsSet[i].a;
            a.b = TestsSet[i].b;
            a.c = TestsSet[i].c;
            a.x1 = &x1;
            a.x2 = &x2;
            int NumberOfRoots = SolveQuadraticEquation(a);
            if(NumberOfRoots != TestsSet[i].CountOfRoots)
            {
                printf("\x1b[31m the number of roots in the test %d is not determined correctly \n \x1b[30m", i+1);
                CountOfFailedTests++;
            }
            else
            {
                if(NumberOfRoots == 1 || NumberOfRoots == 2)
                {
                    if(fabsf((x1*x1*TestsSet[i].a + x1*TestsSet[i].b +TestsSet[i].c)- 0) >= EPS || fabsf((x2*x2*TestsSet[i].a + x2*TestsSet[i].b +TestsSet[i].c)- 0) >= EPS)
                    {
                        printf("\x1b[31m large calculation error in the test number %d \n \x1b[30m", i+1);
                        CountOfFailedTests++;
                    }
                }
        }
    }
    printf("%d / %d %s", CountOfTests - CountOfFailedTests, CountOfTests, "\x1b[32m tests passed successfully \x1b[30m");
}
