#include "main.h"

/**
 * add_hex_upper - adds a given integer to a given buffer
 * as hexadecimal number in uppercase
 * @ap: va_list containing the integer to add
 * @buffer: character buffer
 * @i: index from which to start adding to buffer
 *
 * Return: number of characters added
 */
int add_hex_upper(va_list ap, char *buffer, int i)
{
	unsigned int num = va_arg(ap, unsigned int);
	int j = 0;
	char *num_str;

	num_str = int_to_str(num, 16);
	if (!num_str)
		return (0);

	for (j = 0; num_str[j] != '\0'; j++, i++)
		buffer[i] = num_str[j];

	free(num_str);
	return (j);
}

/**
 * add_hex_lower - adds a given integer to a given buffer
 * as hexadecimal number in lowercase
 * @ap: va_list containing the integer to add
 * @buffer: character buffer
 * @i: index from which to start adding to buffer
 *
 * Return: number of characters added
 */
int add_hex_lower(va_list ap, char *buffer, int i)
{
	unsigned int num = va_arg(ap, unsigned int);
	int j = 0;
	char *num_str;

	num_str = int_to_str(num, 16);
	if (!num_str)
		return (0);

	for (j = 0; num_str[j] != '\0'; j++, i++)
	{
		/* convert uppercase letters to lowercase */
		if (num_str[j] >= 'A' && num_str[j] <= 'Z')
			buffer[i] = num_str[j] + 32;
		else
			buffer[i] = num_str[j];
	}

	free(num_str);
	return (j);
}
