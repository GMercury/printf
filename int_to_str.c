#include "main.h"

/**
 * int_to_str - finds the representation of a given number in a given base
 * @num: decimal number
 * @base: base to represent the number with (2, 8, 10 or 16)
 *
 * Return: string representing num in the given base. Otherwise NULL
 */
char *int_to_str(unsigned long int num, int base)
{
	char *symbols = "0123456789ABCDEF";
	char *result;
	char digits[1024] = {0};
	int i, length = 0;

	/* add the digits of num to digits */
	if (num == 0)
	{
		digits[0] = '0';
		length++;
	}

	while (num > 0)
	{
		digits[length] = symbols[num % base];

		length++;
		num /= base;
	}

	/* copy digits to result array in reverse order */
	result = malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);

	result[length] = '\0';

	for (i = 0; length > 0; i++, length--)
		result[i] = digits[length - 1];

	return (result);
}
