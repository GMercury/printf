#include "main.h"

/**
 * add_str - adds a given string to a given buffer
 * @ap: va_list containing the string to add
 * @buffer: character buffer
 * @i: index from which to start adding to buffer
 *
 * Return: number of characters added
 */
int add_str(va_list ap, char *buffer, int i)
{
	char *str = va_arg(ap, char *);
	int j;

	if (!str)
		str = "(null)";

	for (j = 0; str[j] != '\0'; j++, i++)
		buffer[i] = str[j];

	return (j);
}

/**
 * add_str_print - adds a given string to a given buffer
 * replacing unprintable characters accordingly
 * @ap: va_list containing the string to add
 * @buffer: character buffer
 * @i: index from which to start adding to buffer
 *
 * Return: number of characters added
 */
int add_str_print(va_list ap, char *buffer, int i)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int j, k;

	if (!str)
		str = "(null)";

	for (j = 0, k = 0; str[j] != '\0'; j++, i++)
	{
		if (str[j] < 32 || str[j] >= 127)
		{
			/* print '\x' followed by the hex rep. of the character */
			hex = int_to_str(str[j], 16);
			buffer[i] = '\\';
			buffer[i + 1] = 'x';
			buffer[i + 2] = hex[1] == '\0' ? '0' : hex[0];
			buffer[i + 3] = hex[1] == '\0' ? hex[0] : hex[1];
			i += 3;
			k += 3;
		}
		else
		{
			buffer[i] = str[j];
		}
	}

	return (j + k);
}
