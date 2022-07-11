#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int print_char(va_list args);
int print_percent(va_list args);
int print_int(va_list args);

typedef struct print_spec
{
	char *id;
	int (*fnspec)(va_list);

}specptr;

int (*print_spec(char c))(va_list)
{
        specptr functs_arr[] = {
				{"c", print_char},
                {"%", print_percent},
				{"d", print_int},
				{"i", print_int}
        };
	int flags = 4;

        register int i;

        for (i = 0; i < flags; i++)
		if (functs_arr[i].id[0] == c)
			return (functs_arr[i].fnspec);
	return (NULL);
}

int print_int(va_list args)
{

	unsigned int divisor = 1, i, resp;
	int c = 0;
	int n = va_arg(args, int);
	if (n < 0)
	{
		putchar('-');
		c++;
		n *= -1;
	}

	for (i = 0; n / divisor > 9; i++, divisor *= 10);
	
	for (; divisor >= 1; n %= divisor, divisor /= 10, c++)
	{
		resp = n / divisor;
		putchar('0' + resp);
		
	}

	return (c);
	
}

int print_char(va_list args)
{
	char c = va_arg(args, int);

	if (c == '\0')
	{
		return(write(1, &c, 1));
	}
	putchar(c);
	return (1);
}

int print_percent(va_list args)
{
	(void)args;
	return (putchar('%'));
}

int printk(const char *format, ...)
{
	va_list args;
	int val = 0, i = 0;
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
				val++;
				i++;
			}
			else
			{
				val += func(args);
				i += 2;
				continue;
			}
		}
		else
		{
			putchar(format[i]);
			val++;
			i++;
		}
	}
	va_end(args);
	return (val);
}


int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = printk("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    // printk("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    printk("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);


        return (0);
}
