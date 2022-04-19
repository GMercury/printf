#include "main.h"

/**
 * add_int - adds a given integer to a given buffer as decimal number
 * @ap: va_list containing the integer to add
 * @buffer: character buffer
 * @i: index from which to start adding to buffer
 *
 * Return: number of characters added
 */
int add_int(va_list ap, char *buffer, int i)
{
	int num = va_arg(ap, int);
	int k, j = 0;
	char *num_str;

	/* add '-' in front of negative numbers */
	if (num < 0)
	{
		num = -num;
		buffer[i++] = '-';
		j++;
	}

	num_str = int_to_str(num, 10);
	if (!num_str)
		return (0);

	for (k = 0; num_str[k] != '\0'; k++, i++)
		buffer[i] = num_str[k];

	free(num_str);
	return (j + k);
}

/**
 * add_unsigned_int - adds a given integer to a given buffer as decimal
 * @ap: va_list containing the integer to add
 * @buffer: character buffer
 * @i: index from which to start adding to buffer
 *
 * Return: number of characters added
 */
int add_unsigned_int(va_list ap, char *buffer, int i)
{
	unsigned int num = va_arg(ap, unsigned int);
	int j = 0;
	char *num_str;

	num_str = int_to_str(num, 10);
	if (!num_str)
		return (0);

	for (j = 0; num_str[j] != '\0'; j++, i++)
		buffer[i] = num_str[j];

	free(num_str);
	return (j);
}
