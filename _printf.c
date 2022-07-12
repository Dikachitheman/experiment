#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the print_spec() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into format
 * Return: value of printed chars
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0, i = 0;
	int (*func)(va_list);

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
				func = print_spec(format[i + 1]);
			if (func == NULL)
			{
				putchar(format[i]);
				len++;
				i++;
			}
			else
			{
				len += func(args);
				i += 2;
				continue;
			}
		}
		else
		{
			putchar(format[i]);
			len++;
			i++;
		}
	}
	va_end(args);
	return (len);
}
