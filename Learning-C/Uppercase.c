#include <stdio.h>

void print_number(int n)
{

    int i;

	i = n;
	if (n < 0)
	{
		putchar('-');
		i = -n;
	}

	if (i / 10 != 0)
		print_number(i / 10);

	putchar('0' + (i % 10));
}

int main(void)
{
    print_number(98);
    putchar('\n');
    print_number(402);
    putchar('\n');
    print_number(1024);
    putchar('\n');
    print_number(0);
    putchar('\n');
    print_number(-98);
    putchar('\n');
    return (0);
}