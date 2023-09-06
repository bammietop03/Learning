#include "main.h"
#include <stdio.h>

char buffer[BUFFER_SIZE];

int _putchar(char c)
{
    return write(1, &c, 1);
}

void flush_buffer(char *buffer, char **buf_ptr)
{
    write(1, buffer, *buf_ptr - buffer);
    *buf_ptr = buffer;
}

int print_char(char c, char **buf_ptr)
{
    if (*buf_ptr - buffer >= BUFFER_SIZE)
        flush_buffer(buffer, buf_ptr);

    **buf_ptr = c;
    (*buf_ptr)++;
    return 1;
}

int print_string(char *str, char **buf_ptr)
{
    int count = 0;

    if (!str)
        str = "(null)";

    while (*str)
    {
        if (*buf_ptr - buffer >= BUFFER_SIZE)
            flush_buffer(buffer, buf_ptr);

        **buf_ptr = *str;
        (*buf_ptr)++;
        str++;
        count++;
    }

    return count;
}

int print_number(int num, char **buf_ptr)
{
    if (num == 0)
    {
        if (*buf_ptr - buffer >= BUFFER_SIZE)
            flush_buffer(buffer, buf_ptr);

        **buf_ptr = '0';
        (*buf_ptr)++;
        return 1;
    }

    if (num < 0)
    {
        if (*buf_ptr - buffer >= BUFFER_SIZE)
            flush_buffer(buffer, buf_ptr);

        **buf_ptr = '-';
        (*buf_ptr)++;
        return 1 + print_number(-num, buf_ptr);
    }

    if (num / 10 != 0)
        return print_number(num / 10, buf_ptr) + print_number(num % 10, buf_ptr);

    if (*buf_ptr - buffer >= BUFFER_SIZE)
        flush_buffer(buffer, buf_ptr);

    **buf_ptr = num + '0';
    (*buf_ptr)++;
    return 1;
}

int print_unsigned(unsigned int u_num, char **buf_ptr)
{
    if (u_num == 0)
    {
        if (*buf_ptr - buffer >= BUFFER_SIZE)
            flush_buffer(buffer, buf_ptr);

        **buf_ptr = '0';
        (*buf_ptr)++;
        return 1;
    }

    if (u_num / 10 != 0)
        return print_unsigned(u_num / 10, buf_ptr) + print_unsigned(u_num % 10, buf_ptr);

    if (*buf_ptr - buffer >= BUFFER_SIZE)
        flush_buffer(buffer, buf_ptr);

    **buf_ptr = u_num + '0';
    (*buf_ptr)++;
    return 1;
}

int print_hex_recursive(unsigned int num, char **buf_ptr, int uppercase)
{
    char hex_digits[] = "0123456789abcdef";
    int count = 0;

    if (num / 16 != 0)
        count += print_hex_recursive(num / 16, buf_ptr, uppercase);

    if (*buf_ptr - buffer >= BUFFER_SIZE)
        flush_buffer(buffer, buf_ptr);

    **buf_ptr = uppercase ? toupper(hex_digits[num % 16]) : hex_digits[num % 16];
    (*buf_ptr)++;
    return count + 1;
}

int print_binary_recursive(unsigned int num, char **buf_ptr)
{
    int count = 0;

    if (num / 2 != 0)
        count += print_binary_recursive(num / 2, buf_ptr);

    if (*buf_ptr - buffer >= BUFFER_SIZE)
        flush_buffer(buffer, buf_ptr);

    **buf_ptr = num % 2 + '0';
    (*buf_ptr)++;
    return count + 1;
}

int print_octal(unsigned int oct_num, char **buf_ptr)
{
    if (oct_num == 0)
    {
        if (*buf_ptr - buffer >= BUFFER_SIZE)
            flush_buffer(buffer, buf_ptr);

        **buf_ptr = '0';
        (*buf_ptr)++;
        return 1;
    }

    return print_octal_recursive(oct_num, buf_ptr);
}

int handle_conversion(char c, va_list args, char **buf_ptr)
{
    switch (c)
    {
    case 'c':
        return print_char(va_arg(args, int), buf_ptr);

    case 's':
        return print_string(va_arg(args, char *), buf_ptr);

    case '%':
        if (*buf_ptr - buffer >= BUFFER_SIZE)
            flush_buffer(buffer, buf_ptr);

        **buf_ptr = '%';
        (*buf_ptr)++;
        return 1;

    case 'd':
    case 'i':
        return print_number(va_arg(args, int), buf_ptr);

    case 'u':
        return print_unsigned(va_arg(args, unsigned int), buf_ptr);

    case 'o':
        return print_octal(va_arg(args, unsigned int), buf_ptr);

    case 'x':
        return print_hex_recursive(va_arg(args, unsigned int), buf_ptr, 0);

    case 'X':
        return print_hex_recursive(va_arg(args, unsigned int), buf_ptr, 1);

    case 'b':
        return print_binary_recursive(va_arg(args, unsigned int), buf_ptr);

    default:
        if (*buf_ptr - buffer >= BUFFER_SIZE)
            flush_buffer(buffer, buf_ptr);

        **buf_ptr = '%';
        (*buf_ptr)++;

        if (c != '\0
