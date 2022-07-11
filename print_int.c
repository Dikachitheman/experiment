#include "main.h"

/**
 * print_int - prints an integer
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int print_int(va_list arg)
{

unsigned int divisor = 1, i, resp, len = 0;
int n = va_arg(arg, int);

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

int main()
{
    print_int()
}