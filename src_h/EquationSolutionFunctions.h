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
//----------------------
//!Solves a square equation ax2+bx+c=0
//@param[in] a - a coefficient
//@param[in] b - b coefficient
//@param[in] c - c coefficient
//@param[in] &x1 - index of first root
//@param[in] &x2 - index of second root
//@param[out] CountOfSolves - count of roots
//
//@return Number of roots
//
//@note use to calculate linear_equation(func) and square_equation(func)
//
//-----------------------------------------
enum CountOfSolves SolveQuadraticEquation(equation a);


//-----------------
//solve linear equation bx+c=0
//@param[in] b - b coefficient
//@param[in] c - c coefficient
//@param[out] x - root
//@param[out] number of roots - cout of roots for output function
//@return root
//
//------------------
enum CountOfSolves linear_equation(equation a);


//-----------------
//solve square equation ax2+bx+c=0
//@param[in] a - a coefficient
//@param[in] b - b coefficient
//@param[in] c - c coefficient
//@param[out] x1,x2 - roots
//@param[out] number of roots - cout of roots for output function
//@return roots
//
//------------------
enum CountOfSolves quadratic_equation(equation a);
//check is the double number equally zero
bool is_zero(int a);

#endif
