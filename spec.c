#include "main.h"

int (*get_func)(va_list, char c)
{
	specptr functs[] =
	{
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
		{'%', print_percent}
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






// int i = 0, j = 0, first_index;

// 	first_index = index;
// 	while (functs[i].id)
// 	{
// 		if (functs[index] == functs[i].id[j])
// 		{
// 			if (functs[i].id[j + 1] != '\0')
// 				index++, j++;
// 			else
// 				break;
// 		}
// 		else
// 		{
// 			j = 0;
// 			i++;
// 			index = first_index;
// 		}
// 	}
// 	return (functs[i].fnspec);


// typedef struct print_spec
// {
// 	char *id;
// 	int (*fnspec)(va_list);
// }specptr;
