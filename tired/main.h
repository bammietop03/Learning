#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int _putchar(char c);
int handle_conversion(char c, va_list args, char **buf_ptr);
int print_char(char c, char **buf_ptr);
int print_string(char *str, char **buf_ptr);
int print_number(int num, char **buf_ptr);
int print_unsigned(unsigned int u_num, char **buf_ptr);
int print_octal(unsigned int oct_num, char **buf_ptr);
int print_hex_recursive(unsigned int num, char **buf_ptr, int uppercase);
int print_binary_recursive(unsigned int num, char **buf_ptr);
void flush_buffer(char *buffer, char **buf_ptr);

#endif /* MAIN_H */
