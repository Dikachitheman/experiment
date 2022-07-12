#include "main.h"

/**
 * print_int - prints an integer
 * @args: va_list arguments from _printf()
 * Return: number of chars printed.
 */
int print_int(va_list args)
{

	unsigned int divisor = 1, i, resp, len = 0;
	int n = va_arg(args, int);

	if (n < 0)
	{
		putchar('-');
		len++;
		n *= -1;
	}

	for (i = 0; n / divisor > 9; i++, divisor *= 10)
		;

	for (; divisor >= 1; n %= divisor, divisor /= 10, len++)
	{
		resp = n / divisor;
		putchar('0' + resp);
	}
	return (len);
}
