#ifndef _MAIN_H_
#define _MAIN_H_

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* malloc, free */
#include <stdarg.h> /* va_arg */
#include <unistd.h> /* write */

/**
 * struct print_spec - struct
 * @id: identifier of type to print (e.g. c means char)
 * @fnspec: pointer to funcs that print according to identifier(e.g. print_c)
 */
typedef struct print_spec
{
	char *id;
	int (*fnspec)(va_list);
}specptr;

/* print_alpha */
int print_char(va_list args);
int print_string(va_list args);

/* print_nums */
int print_int(va_list args);
int print_unsigned(va_list args);

/* converter */
char *convert(unsigned long int num, int base, int lowercase);

/* print_bases */
int print_binary(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);

/* print_custom */
int print_S(va_list args);
int print_reverse(va_list args);
int print_rot13(va_list args);

/* print_percent */
int print_percent(va_list args __attribute__((unused)));

/* print_address */
int print_address(va_list args);

/* write_functions */
int _putchar(char c);
int _puts(char *str);

/* _printf */
int _printf(const char *format, ...);

/* print_spec */
int (*print_spec(char c))(va_list);

#endif
