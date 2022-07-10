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
	int (*fnspec)(va_list);
}specptr;

int print_char(va_list list);
int print_str(va_list list);
int print_int(va_list list);
int print_binary(va_list list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_HEX(va_list list);
int print_unsigned(va_list list);
int print_str_unprintable(va_list list);
int print_reverse(va_list list);
int print_address(va_list list);
int print_rot13(va_list list);
int print_percent(va_list list __attribute__((unused)));
int print_number(int n);
int print_unsigned_number(unsigned int n);
int _putchar(char c);
int _printf(const char *format, ...);
int (*get_func(const char c))(va_list, int);

#endif
