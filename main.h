#ifndef _MAIN_H_
#define _MAIN_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h> /* malloc, free */
#include <stdarg.h> /* va_arg */
#include <unistd.h> /* write */

/**
 * struct print_spec - struct
 * @id: identifier of type to print (e.g. c means char)
 * @func: pointer to functions that print according to identifier (e.g. print_c)
 */
typedef struct print_spec
{
	char *id;
	int (*func)(va_list);
} ps;

int _putchar(char c);
int _printf(const char *format, ...);
int (*get_func(const char c))(va_list);

#endif
