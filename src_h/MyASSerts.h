#ifndef MY_ASSERTS_H
#define MY_ASSERTS_H
#define MyASSert(arg) ASS(__FUNCTION__, __FILE__, __LINE__, arg);
void ASS(const char *func, const char *FILE, int LINE, bool condition);
bool IsCertain(int a);


#endif
