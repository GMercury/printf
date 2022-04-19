#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: a character string composed of zero or more directives
 *
 * Return: number of characters printed. Otherwise -1
 */
int _printf(const char *format, ...)
{
	/* use character buffer to call write as few times as possible */
	char buffer[SIZE] = {0};
	int f_idx, b_idx;
	int (*f)(va_list, char *, int);
	va_list ap;

	/* only print valid format strings */
	if (format == NULL)
		return (-1);

	va_start(ap, format);
	/* check each character in format */
	for (f_idx = 0, b_idx = 0; format[f_idx] != '\0'; f_idx++)
	{
		/* if the current character is % check the next character */
		if (format[f_idx] == '%')
		{
			if (format[f_idx + 1] == '\0')
				return (-1);
			/* get correct print function */
			f = get_sp_func(format[++f_idx]);
			if (f)
				b_idx += f(ap, buffer, b_idx);
			else
			{
				buffer[b_idx++] = '%';
				buffer[b_idx++] = format[f_idx];
			}
		}
		else
			buffer[b_idx++] = format[f_idx];
	}

	va_end(ap);
	write(1, buffer, b_idx);
	return (b_idx);
}
