#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int value;
int a = 8;
int b = 88;
int print_char(va_list);
int print_int(va_list);
int print_str(va_list);

typedef struct print_spec
{
	char *id;
	int (*fnspec)(va_list);

}specptr;

int (*spec(const char c))(va_list)
{
        specptr functs[] =
	{

		{'s', print_str},
		{'d', print_int},
		{'i', print_int},

                {NULL, NULL}
        };


        int i;

        for (i = 0; functs[i].id != NULL; i++)
        {
                if (functs[i].id == c)
                        return(functs[i].fnspec);
        }
	return (NULL);
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

int print_str(va_list args)
{
         return (a / b);
}

int print_int(va_list args)
{
        return (a * b);
}

int printk(const char *format, ...)
{
	int (*func)(va_list);
        va_list args;
	int i = 0, val = 0;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
        va_start(args, format);

        while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
				func = spec(*format[i + 1]);
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
	printk("Character:[%c]", 'H');
        printf("\n");
	printf("Character:[%c]", 'H');
	printf("\n");
        return (0);
}
