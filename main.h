#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INT {0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2


/**
 * struct parameters - parameters struct
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 * @precision: field precision specified
 * @minus_flag: on if_flag specified
 *
 */
typedef struct parameters
{
	unsigned int l_modifier		: 1;
	unsigned int h_modifier         : 1;
	unsigned int precision;
	unsigned int minus_flag         : 1;
} params_t;



/**
 * struct specifier - struct token
 *
 * @specifier: format token
 * @f: the function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;


/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c module */
int print_char(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);

/* number.c module */
int print_address(va_list ap, params_t *params);

/* specifier.c module */
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_modifier(char *s, params_t *params);

/* convert_number.c module */
int print_binary(va_list ap, params_t *params);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rot13(va_list ap, params_t *params);

/* print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* params.c module */
void init_params(params_t *params, va_list ap);

/* string_fields.c module */
char *get_percision(char *p, params_t *params, va_list ap);

/* _printf.c module */
int _printf(const char *format, ...);

#endif
