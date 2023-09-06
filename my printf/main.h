#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Function prototypes */
int _putchar(char c);
int _printf(const char *format, ...);
int handle_conversion(char c, va_list args);
int print_string(const char *str);
int print_number(int num);

#endif /* MAIN_H */



