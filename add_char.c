#include "main.h"

/**
 * add_char - adds a given character to a given buffer
 * @ap: va_list containing the character to add
 * @buffer: character buffer
 * @i: index from which to start adding to buffer
 *
 * Return: 1(number of characters added)
 */
int add_char(va_list ap, char *buffer, int i)
{
	char c = (char) va_arg(ap, int);

	buffer[i] = c;

	return (1);
}
