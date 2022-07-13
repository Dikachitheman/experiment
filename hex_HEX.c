#include "main.h"

/**
 * print_hexa - prints an unsigned int in hexadecimal form
 * @n: unsigned int to print
 * @c: flag to determine case of printing (0 = lower, 1 = upper)
 * Return: number of digits printed
 */
int print_hexa(unsigned int n, unsigned int c)
{
	unsigned int a[8];
	unsigned int i, m, sum;
	char diff;
	int count;

	m = 268435456;
	if (c)
		diff = 'A' - ':';
	else
		diff = 'a' - ':';
	a[0] = n / m;
	for (i = 1; i < 8; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}
	sum = 0, count = 0;
	for (i = 0; i < 8; i++)
	{
		sum += a[i];
		if (sum || i == 7)
		{
			if (a[i] < 10)
				putchar('0' + a[i]);
			else
				putchar('0' + diff + a[i]);
			count++;
		}
	}
	return (count);
}
/**
 * print_hex - takes an unsigned int and prints it in lowercase hex notation
 * @x: unsigned int(s) to print
 *
 * Return: number of digits printed
 */
int print_hex(va_list x)
{
	return (print_hexa(va_arg(x, unsigned int), 0));
}

/**
 * print_HEX - takes an unsigned int and prints it in uppercase hex notation
 * @X: unsigned int(s) to print
 *
 * Return: number of digits printed
 */
int print_HEX(va_list X)
{
	return (print_hexa(va_arg(X, unsigned int), 1));
}
