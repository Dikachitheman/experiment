#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int print_char(va_list args);
int print_percent(va_list args);
int print_binary(va_list args);
int print_string(va_list args);
int print_unsigned(va_list arg);
int print_oct(va_list arg);
int print_hex(va_list args);
int print_Hex(va_list args);


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
		{"b", print_binary},
		{"u", print_unsigned},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_Hex}
        };
	int flags = 9;

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

/**
 * print_unsigned - prints an unsigned int.
 * @arg: argument
 * Return: 0
 */

int print_unsigned(va_list arg)
{
int divisor = 1, i, resp;
unsigned int n = va_arg(arg, unsigned int);

for (i = 0; n / divisor > 9; i++, divisor *= 10)
;

for (; divisor >= 1; n %= divisor, divisor /= 10)
{
	resp = n / divisor;
	putchar('0' + resp);
}
return (i + 1);
}

int print_oct(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int copy;
	char *octa;
	int i, j, charPrinted = 0;

	if (num == 0)
		return (putchar('0'));
	for (copy = num; copy != 0; j++)
	{
		copy = copy / 8;
	}
	octa = malloc(j);
	if (!octa)
		return (-1);

	for (i = j - 1; i >= 0; i--)
	{
		octa[i] = num % 8 + '0';
		num = num / 8;
	}

	for (i = 0; i < j && octa[i] == '0'; i++)
		;
	for (; i < j; i++)
	{
		putchar(octa[i]);
		charPrinted++;
	}
	free(octa);
	return (charPrinted);
}

int print_Hex(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char c = 'X';
	unsigned int num2;
	int i, j, remainder, nbrCharacters = 0;
	char *numhex;

	for (num2 = num; num2 != 0; nbrCharacters++, num2 /= 16)
	;

	numhex = malloc(nbrCharacters);
	for (i = 0; num != 0; i++)
	{
		remainder = num % 16;
		if (remainder < 10)
			numhex[i] = remainder + '0';
		else
			numhex[i] = remainder - 10 + c;
		num = num / 16;
	}
	for (j = i - 1; j >= 0; j--)
		putchar(numhex[j]);
	free(numhex);
	return (nbrCharacters);
}

int print_hex(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char c = 'x';
	unsigned int num2;
	int i, j, remainder, nbrCharacters = 0;
	char *numhex;

	for (num2 = num; num2 != 0; nbrCharacters++, num2 /= 16)
	;

	numhex = malloc(nbrCharacters);
	for (i = 0; num != 0; i++)
	{
		remainder = num % 16;
		if (remainder < 10)
			numhex[i] = remainder + '0';
		else
			numhex[i] = remainder - 10 + c;
		num = num / 16;
	}
	for (j = i - 1; j >= 0; j--)
		putchar(numhex[j]);
	free(numhex);
	return (nbrCharacters);
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
	printf("Character:[%u]\n", 89);
	printk("Character:[%u]\n", -89);
	printf("Character:[%c]\n", 'H');
	printk("Binary:[%b]\n", 4);
	printf("String:[%s]\n", "I am a string !");
	printk("Percent:[%%%%]\n");
	printf("Percent:[%%%%]\n");
	printk("Unsigned hexadecimal:[%x, %X]\n", 4567, 4567);
	printf("Unsigned hexadecimal:[%x, %X]\n", 4567, 4567);
        return (0);
}
