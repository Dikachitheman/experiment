#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int print_char(va_list args);
int print_percent(va_list args);
int print_string(va_list args);
int print_binary(va_list args);

typedef struct print_spec
{
	char *id;
	int (*fnspec)(va_list);

}specptr;

int (*print_spec(char c))(va_list)
{
        specptr functs_arr[] = {
		{"c", print_char},
		{"s", print_string},
        {"%", print_percent},
		{"b", print_binary}
        };
	int flags = 4;

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

int print_string(va_list args)
{
	int i;
	char *str = va_arg(args, char*);

	if (str == NULL)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	for (i = 0; str[i]; i++)
		putchar(str[i]);

	return (i);
}

int print_binary(va_list args)
{
	int n = va_arg(args, int);
	int b = 1, i, j, len = 0;
	int *ar;
	ar = (int*)malloc(n * sizeof(char));

	for (i = 0; b < n ; i++)
		{
			ar[i] = b;
			b = b * 2;
			len++;
		}

	// for (i = 0; i < len; i++)
	// 	{
	// 		if (ar[i])
	// 		{
	// 			printf("%d, %d, %d\n", ar[i], b, len);
	// 		}
	// 	}

		// printf("\n");

	int dif = n;
	int p, k = 1, u = 0;
	int pr[len];

	for (u; u < len; u++)
	{
		pr[j] = dif;
		if (dif >= ar[len - k])
		{
			dif = dif - ar[len - k];
			pr[j] = dif;
			putchar('0' + 1);
			j++;
		}
		else 
		{
			putchar('0' + 0);
		}
        k++;
	}
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
	printk("Character:[%b]\n", 9);
	printf("Character:[%c]\n", 'H');
	printk("String:[%b]\n", 4);
	printf("String:[%s]\n", "I am a string !");

        return (0);
}
