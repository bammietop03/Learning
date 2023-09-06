#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    char c = (char)va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char*);
                    while (*str) {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    count++;
                    break;
                }
                default:
                    // Ignore unsupported conversion specifiers
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}

int main() {
    int num = 42;
    char ch = 'A';
    char str[] = "Hello, world!";

    int count = _printf("Number: %d, Character: %c, String: %s, Percent: %%\n", num, ch, str);
    printf("Number of characters printed: %d\n", count);

    return 0;
}
