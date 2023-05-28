#include "main.h"

/**
 * get_specifier - finds the format func
 * @s: the format string
 * Return: number of bytes printed
 */

int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"p", print_address},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifier[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format func
 * @s: format string
 * @ap: argument pointer
 * @params: parameters struct
 *
 * Return: number of bytes printed
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - finds the flag func
 * @s: dormat string
 * @params: parameters struct
 *
 * Return: if flag is valid
 */
int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '-':
			i = params->minus_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - finds the modifier func
 * @s: format string
 * @params: parameters struct
 *
 * Return: if modifier is valid
 */
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}
