#include <limits.h>
#include <stdio.h>
#include "main.h"

int print_octal(va_list o)
{
	unsigned int a[11];
	unsigned int i, m, n, sum;
	int count;

	n = va_arg(o, unsigned int);
	m = 1073741824; /* (8 ^ 10)*/
	a[0] = n / m;
	for (i = 1; i < 11; i++)
	{
		m /= 8;
		a[i] = (n / m) % 8;
	}
	sum = 0, count = 0;
	for (i = 0; i < 11; i++)
	{
		sum += a[i];
		if (sum || i == 10)
		{
			putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}

/**
 * print_binary - takes an unsigned int and prints it in binary notation
 * @b: unsigned int to print
 * Return: number of digits printed
 */
int print_binary(va_list b)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	n = va_arg(b, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	sum = 0, count = 0;
	for (i = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}

int main(void)
{
	unsigned int ui;
	long int res;

	res = (long int)INT_MAX * 2;
	ui = (unsigned int)INT_MAX + 1024;

	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("%o\n", 0);
	printf("%o\n", 0);
	_printf("%o + %o = %o\n", INT_MAX, INT_MAX, res);
	printf("%o + %o = %o\n", INT_MAX, INT_MAX, res);
	_printf("%o - %o = %o\n", 2048, 1024, 1024);
	printf("%o - %o = %o\n", 2048, 1024, 1024);
	_printf("There is %o bytes in %o KB\n", 1024, 1);
	printf("There is %o bytes in %o KB\n", 1024, 1);
	_printf("%b + %b = %b\n", INT_MAX, INT_MAX, res);
	printf("%b + %b = %b\n", INT_MAX, INT_MAX, res);
	_printf("%b\n", 0);
	printf("%b\n", 0);
	_printf("There is %b bytes in %b KB\n", 1024, 1);
	printf("There is %b bytes in %b KB\n", 1024, 1);
	_printf("%b - %b = %b\n", 2048, 1024, 1024);
	printf("%b - %b = %b\n", 2048, 1024, 1024);
	_printf("%b\n", 98);
	printf("%b\n", 98);
	_printf("%u == %o == %x == %X\n", 1024, 1024, 1024, 1024);
	_printf("%x\n", 0);
	_printf("%X\n", 0);

	return (0);
}
