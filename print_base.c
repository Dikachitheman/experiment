#include "main.h"

/**
 * print_oct - prints number in octal base.
 * @arg: list containing octal number to be printed
 * Return: number of octals printed
 */

int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int copy;
	char *octa;
	int i, j, charPrinted = 0;

	if (num == 0)
		return (putchar('0'));
	for (copy = num; copy != 0; j++)
	{
		copy = copy / 2;
	}
	octa = malloc(j);
	if (!octa)
		return (-1);

	for (i = j - 1; i >= 0; i--)
	{
		octa[i] = num % 2 + '0';
		num = num / 2;
	}

	for (i = 0; i < j && octa[i] == '0'; i++)
		;
	for (; i < j; i++)
	{
		putchar(octa[i]);
		charPrinted++;
	}
	free(octa);
	return (charPrinted);
}



#include "main.h"

/**
 * print_oct - prints number in octal base.
 * @arg: list containing octal number to be printed
 * Return: number of octals printed
 */

int print_oct(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int copy;
	char *octa;
	int i, j, charPrinted = 0;

	if (num == 0)
		return (putchar('0'));
	for (copy = num; copy != 0; j++)
	{
		copy = copy / 8;
	}
	octa = malloc(j);
	if (!octa)
		return (-1);

	for (i = j - 1; i >= 0; i--)
	{
		octa[i] = num % 8 + '0';
		num = num / 8;
	}

	for (i = 0; i < j && octa[i] == '0'; i++);
	for (; i < j; i++)
	{
		putchar(octa[i]);
		charPrinted++;
	}
	free(octa);
	return (charPrinted);
}
