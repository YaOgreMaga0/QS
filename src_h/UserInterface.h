#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include <string.h>
//secure input for coefficients
void NumbersScanner(double* a, double* b, double* c);
//print answers
void OutputAnswers(enum CountOfSolves NumberOfRoots, double x1, double x2);
//clean input buffer
int ClearStdin();
//user interface
int UserI();
#endif
