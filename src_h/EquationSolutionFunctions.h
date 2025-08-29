#ifndef EQUATION_SOLUTION_FUNCTIONS_H
#define EQUATION_SOLUTION_FUNCTIONS_H
#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"

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
