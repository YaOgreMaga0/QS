#ifndef EQUATION_SOLUTION_FUNCTIONS_H
#define EQUATION_SOLUTION_FUNCTIONS_H

const double EPS = 0.000001;

struct equation
{
    double a, b, c;
    double* x1;
    double* x2;
};

struct test
{
    double a;
    double b;
    double c;
    int CountOfRoots;
};

enum CountOfSolves
{
    Zero,
    One,
    Two,
    Infinity
};

enum CountOfSolves SolveQuadraticEquation(equation a);

enum CountOfSolves linear_equation(equation a);
enum CountOfSolves quadratic_equation(equation a);
bool is_zero(int a);

#endif
