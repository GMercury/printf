#include "main.h"

/**
 * add_rot - adds a given string to a given buffer encoded using rot13
 * @ap: va_list containing the string to add
 * @buffer: character buffer
 * @i: index from which to start adding to buffer
 *
 * Return: number of characters added. Otherwise 0
 */
int add_rot(va_list ap, char *buffer, int i)
{
	char *str = va_arg(ap, char *);
	char *rot;
	int j;

	if (!str)
		return (copy_to_buff("(null)", buffer, i));

	/* encode string */
	rot = rot13(str);
	if (!rot)
		return (0);

	for (j = 0; rot[j] != '\0'; j++, i++)
		buffer[i] = rot[j];

	free(rot);
	return (j);
}

/**
* rot13 -  encodes a string using rot13
* @s: string to be encoded
*
* Return: pointer to the encoded string
*/
char *rot13(char *s)
{
	/* get the length of the string */
	int length, i;
	char *result;

	/* copy encoded characters to result */
	length = _strlen(s);
	result = malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);

	result[length] = '\0';

	for (i = 0; i < length; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			result[i] = 'a' + (s[i] - 'a' + 13) % 26;
		else if (s[i] >= 'A' && s[i] <= 'Z')
			result[i] = 'A' + (s[i] - 'A' + 13) % 26;
		else
			result[i] = s[i];
	}

	return (result);
}
