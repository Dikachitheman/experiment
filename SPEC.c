/**
 * get_func - select function for conversion char
 * @c: char to check
 * Return: pointer to function
 */
int (*get_func(const char c))(va_list)
{
	int i = 0;

	print_spec ps[] = {
		{"c", print_char},
		{"i", print_int},
		{"d", print_int},
		{"s", print_str},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{"u", print_unsigned},
		{"S", print_unprintable_str},
		{"r", print_reverse},
		{"p", print_address},
		{"R", print_rot13},
		{"%", print_percent}
	};
	int specs = 14;

	for (i = 0; i < specs; i++)
		if (ps[i].id == c)
			return (ps[i].func);
	return (NULL);
}
