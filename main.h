#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
void print_char(va_list list, int *length);
void print_str(va_list list, int *length);
void checkIsCharOrStr(va_list list, char format, int *length);
#endif
