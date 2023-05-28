#include "main.h"

/**
 * init_params - clears struct fields and reset buf
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: void
 */
void init_params(params_t *params, va_list ap)
{
	params->h_modifier = 0;
	params->l_modifier = 0;
	params->precision = UNIT_MAX;
	params->mminus_flag = 0;

	(void)ap;
}
