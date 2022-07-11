#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int value;
int a = 8;
int b = 88;
int print_char(int a, int b);
int print_int(int a, int b);
int print_str(int a, int b);

typedef struct print_spec
{
	char *id;
	int (*fnspec)(int a, int b);
        
}specptr;

int (*spec(char *c))(int, int)
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
                if (*functs[i].id = *c)
                        return(functs[i].fnspec);
        }
}

int print_char(int a, int b)
{
        return (a + b);
}

int print_str(int a, int b)
{
         return (a / b);
}

int print_int(int a, int b)
{
        return (a * b);
}

int printk(const char *format, ...)
{
    
        va_list args;
        va_start(args, format);

        for (int i = 0; format && format[i]; i++)
        {
                if(format[i] == '%') 
                {
                        int val = va_arg(args, int);
                        printf (" %d ", val);
                }
                else
                        putchar(format[i]);

        }
}

int main()
{
        printk("erhfjnn%%%%",5,6,88,889);
        printf("\n");
        char u = 'd';
        spec(&u);
        return 0;
}
