#include "main.h"

int (*get_func(const char c))(va_list, int)
{
	specptr functs[] = {
		{'c', print_char},
		{'s', print_str},
		{'d', print_int},
		{'i', print_int},
		{'u', print_unsigned_number},
		{'o', print_octal},
		{'x', print_hex},
		{'X', print_HEX},
		{'R', print_rot13},
		{'b', print_binary},
		// {'S', print_Str}
	};

	int i;

	for (i = 0; functs[i].id; i++)
	{
		if (c == functs[i].id)
		{
			return (functs[i].fnspec);
		}
	}

	return (NULL);
}
