#include "main.h"

/**
 * print_S - non printable characters
 * (0 < ASCII value < 32 or >= 127) are printed this way:\x, followed by the
 * ASCII code value in hexadecimal (uppercase - always 2 characters)
 * @args: va_list arguments from _printf()
 * Return: number of character printed
 */
int print_S(va_list args)
{
	int i, count = 0;
	char *res;
	char *s = va_arg(args, char *);

	if (!s)
		return (puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			puts("\\x");
			count += 2;
			res = convert(s[i], 16, 0);
			if (!res[1])
				count += putchar('0');
			count += puts(res);
		}
		else
			count += putchar(s[i]);
	}
	return (count);
}

/**
 * print_reverse - prints a string in reverse
 * @args: va_list arguments from _printf
 * Return: length of the printed string
 */
int print_reverse(va_list args)
{
	int i = 0, j;
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	while (str[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		putchar(str[j]);

	return (i);
}

/**
 * print_rot13 - prints a string using rot13
 * @args: va_list of arguments from _printf()
 * Return: length of the printed string
 */
int print_rot13(va_list args)
{
	int i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "mnopqrstuvwxyzabcdefghijklMNOPQRSTUVWXYZABCDEFGHIJKL";
	char *s = va_arg(args, char *);

	for (j = 0; s[j]; j++)
	{
		if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
			putchar(s[j]);
		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (s[j] == rot13[i])
					putchar(ROT13[i]);
			}
		}
	}

	return (j);
}
