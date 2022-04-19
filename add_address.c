#include "main.h"

/**
 * add_address - adds a given integer to a given buffer
 * as a large hexadecimal number in lowercase appended with 0x
 * @ap: va_list containing the integer to add
 * @buffer: character buffer
 * @i: index from which to start adding to buffer
 *
 * Return: number of characters added
 */
int add_address(va_list ap, char *buffer, int i)
{
	unsigned long int num = va_arg(ap, unsigned long int);
	int j, k = 0;
	char *num_str;

	num_str = int_to_str(num, 16);
	if (!num_str)
		return (0);

	/* add "0x" in front of the number */
	buffer[i] = '0';
	buffer[i + 1] = 'x';
	i += 2;
	k += 2;

	for (j = 0; num_str[j] != '\0'; j++, i++)
	{
		/* convert uppercase letters to lowercase */
		if (num_str[j] >= 'A' && num_str[j] <= 'Z')
			buffer[i] = num_str[j] + 32;
		else
			buffer[i] = num_str[j];
	}

	free(num_str);
	return (j + k);
}
