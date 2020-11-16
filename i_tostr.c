/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   i_tostr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/16 16:59:14 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

char	*i_tostr(t_special *sp, va_list ap)
{
	char	*num_str;
	long	num;
	long	precision;

	num = (long)va_arg(ap, int);
	if (sp->precision >= 0)
		precision = sp->precision;
	else if (sp->precision0 >= 0)
		precision = num < 0 ? ft_max(sp->precision0 - 1, 0) : sp->precision0;
	else
		precision = -1;
	if (precision > 0)
		num_str = ft_numtostr_precision(num, precision);
	else
		num_str = ft_numtostr(num);
	if (sp->field_width >= 0)
	{
		if (sp->flags[(size_t)'-'] > 0)
			ft_padend(&num_str, sp->field_width, ' ');
		else
			ft_padstart(&num_str, sp->field_width, ' ');
	}
	return (num_str);
}
