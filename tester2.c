#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int print_char(va_list args);
int print_percent(va_list args);

typedef struct print_spec
{
	char *id;
	int (*fnspec)(va_list);

}specptr;

int (*print_spec(char c))(va_list)
{
        specptr functs_arr[] = {
		{"c", print_char},
                {"%", print_percent}
        };
	int flags = 2;

        register int i;

        for (i = 0; i < flags; i++)
		if (functs_arr[i].id[0] == c)
			return (functs_arr[i].fnspec);
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
    printk("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    printk("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    printk("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    printk("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    printk("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printk("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    printk("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    printk("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = printk("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    printk("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
   printk("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");

        return (0);
}
