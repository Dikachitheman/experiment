#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h> /* malloc, free */
#include <stdarg.h> /* va_arg */
#include <unistd.h> /* write */

/**
 * struct types - struct
 * @id: identifier of type to print (e.g. c means char)
 * @func: pointer to functions that print according to identifier (e.g. print_c)
 */
typedef struct types
{
	char id;
	char* (*func)(va_list);
} print;

int _putchar(char c);
int _printf(const char *format, ...);

#endif
