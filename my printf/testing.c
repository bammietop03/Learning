#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: The character to write
 * Return: On success, returns the number of characters written. On error, -1 is returned.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _printf - Produces output according to a format
 * @format: The format string
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;

	va_start(args, format);

	while ((c = *format++))
	{
		if (c == '%')
		{
			c = *format++;
			count += handle_conversion(c, args);
		}
		else
		{
			_putchar(c);
			count++;
		}
	}

	va_end(args);
	return count;
}

/**
 * handle_conversion - Handles the conversion specifiers
 * @c: The conversion specifier character
 * @args: The va_list containing the arguments
 * Return: The number of characters printed for this conversion specifier
 */
int handle_conversion(char c, va_list args)
{
	if (c == 'c')
	{
		char ch = (char)va_arg(args, int);
		_putchar(ch);
		return 1;
	}
	else if (c == 's')
	{
		char *str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		return print_string(str);
	}
	else if (c == '%')
	{
		_putchar('%');
		return 1;
	}
	else if (c == 'd' || c == 'i')
	{
		int num = va_arg(args, int);
		return print_number(num);
	}
	else
	{
		_putchar('%');
		_putchar(c);
		return 2;
	}
}

/**
 * print_string - Prints a string
 * @str: The string to print
 * Return: The number of characters printed
 */
int print_string(const char *str)
{
	int count = 0;
	while (*str)
	{
		_putchar(*str);
		str++;
		count++;
	}
	return count;
}

/**
 * print_number - Prints an integer
 * @num: The number to print
 * Return: The number of characters printed
 */
int print_number(int num)
{
	unsigned int n;
	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		n = -num;
	}
	else
		n = num;

	if (n / 10 != 0)
		count += print_number(n / 10);

	_putchar(n % 10 + '0');
	count++;

	return count;
}

int main()
{
    int len = _printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d, %i]\n", len, len);
    _printf("String:[%s]\n", "I am a string !");
    return (0);
}