#include "main.h"

/**
 * hex_print_S - prints a char's ASCII value in uppercase hex
 * @c: char to print
 * Return: number of chars printed (always 2)
 */
int hex_print_S(char c)
{
	int count;
	char diff = 'A' - ':';
	char d[2];

	d[0] = c / 16;
	d[1] = c % 16;
	for (count = 0; count < 2; count++)
	{
		if (d[count] >= 10)
			putchar('0' + diff + d[count]);
		else
			putchar('0' + d[count]);
	}
	return (count);
}

/**
 * print_S - non printable characters
 * Description: (0 < ASCII value < 32 or >= 127) are printed this way:\x,
 * followed by the
 * ASCII code value in hexadecimal (uppercase - always 2 characters)
 * @args: va_list arguments from _printf()
 * Return: number of character printed
 */
int print_S(va_list args)
{
	unsigned int i;
	int count = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += putchar('\\');
			count += putchar('x');
			count += hex_print_S(str[i]);
		}
		else
		{
			putchar(str[i]);
			count++;
		}
	}

	return (i);
}

/**
 * print_reverse - prints a string in reverse
 * @args: va_list arguments from _printf()
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
 * print_rot13 - encrypts string with rot13
 * @args: va_list arguments from _printf()
 * Return: number of char printed
 */
int print_rot13(va_list args)
{
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				putchar(out[j]);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			putchar(str[i]);
			count++;
		}
	}
	return (count);
}

int main(void)
{
	_printf("%S\n", "Best\nSchool");
	printf("%S\n", "Best\nSchool");
	_printf("Unknown:[%r]\n", "French");
	printf("Unknown:[%r]\n", "french");
	_printf("Rot13:[%R]\n", "French");
	printf("Rot13:[%R]\n", "French");
	return (0);
}
