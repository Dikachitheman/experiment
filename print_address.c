#include "main.h"

/**
 * _pow - calculates an exponent
 * @base: base of exponent
 * @exponent: exponent of number
 * Return: base ^ exponent
 */
unsigned long _pow(unsigned int base, unsigned int exponent)
{
	unsigned int i;
	unsigned long ans = base;

	for (i = 1; i < exponent; i++)
	{
		ans *= base;
	}
	return (ans);
}

/**
 * print_address - prints address of input in hex format
 * @p: address to print from _printf()
 * Return: number of char printed
 */

int print_address(va_list p)
{
	int count = 0;
	unsigned int a[16];
	unsigned int i, sum;
	unsigned long n, m;
	char *str = "(nil)";

	n = va_arg(p, unsigned long);
	if (n == 0)
	{
		for (i = 0; str[i]; i++)
		{
			putchar(str[i]);
			count++;
		}
		return (count);
	}
	putchar('0'), putchar('x');
	count = 2;
	m = _pow(16, 15); /* 16 ^ 15 */
	a[0] = n / m;
	for (i = 1; i < 16; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}

	sum = 0;
	for (i = 0; i < 16; i++)
	{
		sum += a[i];
		if (sum || i == 15)
		{
			if (a[i] < 10)
				putchar('0' + a[i]);
			else
				putchar('0' + ('a' - ':') + a[i]);
			count++;
		}
	}
	return (count);
}
