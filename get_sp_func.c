#include "main.h"

/**
 * get_sp_func - selects the correct function using a given character
 * @c: specifier character passed as argument to the program
 *
 * Return: a pointer to the function that corresponds to c. Otherwise NULL
 */
int (*get_sp_func(char c))(va_list, char *, int)
{
	sp_t sps[] = {
		{'c', add_char},
		{'s', add_str},
		{'S', add_str_print},
		{'%', add_percent},
		{'d', add_int},
		{'i', add_int},
		{'b', add_bin},
		{'x', add_hex_lower},
		{'X', add_hex_upper},
		{'o', add_oct},
		{'u', add_unsigned_int},
		{'r', add_rev},
		{'R', add_rot},
		{'p', add_address},
		{'\0', NULL}
	};

	int i = 0;

	while (sps[i].sp)
	{
		if (c == sps[i].sp)
			return (sps[i].f);

		i++;
	}

	return (NULL);
}
