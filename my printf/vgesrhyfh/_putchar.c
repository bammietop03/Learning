#include <unistd.h>




/**
 * print_str - Prints a string using _putchar
 * @str: the string to print
 */
void print_str(const char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
}