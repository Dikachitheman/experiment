#include "main.h"

/**
 * print_string - loops through a string and prints every character.
 * @args: va_list arguments from _printf
 *
 * Return: number of characters written
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);

	if (!s)
		s = "(null)";
	return (_puts(s));
}

/**
 * print_char - prints characters
 * @args: va_list arguments from _printf
 *
 * Return: 1 on success.
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	if (c == '\0')
	{
		return (write(1, &c, 1));
	}
	_putchar(c);
	return (1);
}
