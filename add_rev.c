#include "main.h"

/**
 * add_rev - adds a given string to a given buffer in reverse
 * @ap: va_list containing the string to add
 * @buffer: character buffer
 * @i: index from which to start adding to buffer
 *
 * Return: number of characters added. Otherwise 0
 */
int add_rev(va_list ap, char *buffer, int i)
{
	char *str = va_arg(ap, char *);
	char *rev;
	int j;

	if (!str)
		return (0);

	/* reverse string */
	rev = rev_string(str);
	if (!rev)
		return (0);

	for (j = 0; rev[j] != '\0'; j++, i++)
		buffer[i] = rev[j];

	free(rev);
	return (j);
}

/**
 * _strlen - finds the length of a string
 * @s: address of first character in the string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s)
	{
		length++;
		s++;
	}

	return (length);
}

/**
 * rev_string - finds the reverse of a given string
 * @s: string
 *
 * Return: reversed string. Otherwise NULL
 */
char *rev_string(char *s)
{
	/* get the length of the string */
	int length, i;
	char *result;

	/* copy characters to result array in reverse order */
	length = _strlen(s);
	result = malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);

	result[length] = '\0';

	for (i = 0; length > 0; i++, length--)
		result[i] = s[length - 1];

	return (result);
}

