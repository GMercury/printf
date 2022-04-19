#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 1024000 /* buffer size */

/**
 * struct sp - Struct sp
 *
 * @sp: The specifier
 * @f: The function associated
 */
typedef struct sp
{
	char sp;
	int (*f)(va_list, char *, int);
} sp_t;

int _printf(const char *format, ...);
int (*get_sp_func(char c))(va_list, char *, int);
int add_char(va_list ap, char *buffer, int i);
int add_str(va_list ap, char *buffer, int i);
int add_percent(va_list ap, char *buffer, int i);
char *int_to_str(unsigned int num, int base);
int add_int(va_list ap, char *buffer, int i);
int add_unsigned_int(va_list ap, char *buffer, int i);
int add_bin(va_list ap, char *buffer, int i);
int add_hex_lower(va_list ap, char *buffer, int i);
int add_hex_upper(va_list ap, char *buffer, int i);
int add_oct(va_list ap, char *buffer, int i);
int _strlen(char *s);
char *rev_string(char *s);
int add_rev(va_list ap, char *buffer, int i);
char *rot13(char *s);
int add_rot(va_list ap, char *buffer, int i);
int add_str_print(va_list ap, char *buffer, int i);

#endif
