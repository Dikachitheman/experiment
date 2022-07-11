#include "main.h"

/**
 * _printf - Reproduce behaviour of printf function from the standard library
 * @format: format string
 * Return: value of printed chars
 */
int _printf(const char *format, ...)
{
	va_list list;
	int len = 0, i = 0;
	int (*func)();

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(list, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
				func = get_func(format[i + 1]);
			if (func == NULL)
			{
				_putchar(format[i]);
				len++;
				i++;
			}
			else
			{
				len += func(list);
				i += 2;
				continue;
			}
		}
		else
		{
			_putchar(format[i]);
			len++;
			i++;
		}
	}
	va_end(list);
	return (len);
}
