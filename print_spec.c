#include "main.h"

/**
 * print_spec - selects the right printing function
 * depending on the conversion specifier passed to _printf()
 * @c: character that holds the conversion specifier pointer
 * Description: the function loops through the structs array functs_arr[] to
 * find a match between the specifier passed to _printf
 * and the first element of the struct, and then the appropriate
 * printing function
 * Return: a pointer to the matching printing function
 */
int (*print_spec(char c))(va_list)
{
	specptr functs_arr[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"S", print_S},
		{"r", print_reverse},
		{"R", print_rot13}
	};
	int flags = 8;

	register int i;

	for (i = 0; i < flags; i++)
		if (functs_arr[i].id[0] == c)
			return (functs_arr[i].fnspec);
	return (NULL);
}
