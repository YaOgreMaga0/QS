#ifndef MY_ASSERTS_H
#define MY_ASSERTS_H
#define MyASSert(arg) ASS(__FUNCTION__, __FILE__, __LINE__, arg);
///checks the condition for the correct launch of the function
void ASS(const char *func, const char *FILE, int LINE, bool condition);
///checks a number for finiteness
bool IsCertain(int a);


#endif
