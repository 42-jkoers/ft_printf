/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handlers2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/16 17:09:26 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdbool.h>
#include <stdarg.h>

char	*u_tostr(t_special *sp, va_list ap)
{
	char			*num_str;
	unsigned long	num;
	long			precision;

	num = (unsigned long)va_arg(ap, int);
	if (sp->precision >= 0)
		precision = sp->precision;
	else if (sp->precision0 >= 0)
		precision = sp->precision0;
	else
		precision = -1;
	if (precision > 0)
		num_str = ft_numtostr_precision_u(num, precision);
	else
		num_str = ft_numtostr_u(num);
	if (sp->field_width >= 0)
	{
		if (sp->flags[(size_t)'-'] > 0)
			ft_padend(&num_str, sp->field_width, ' ');
		else
			ft_padstart(&num_str, sp->field_width, ' ');
	}
	return (num_str);
}

char	*x_tostr(t_special *sp, va_list ap)
{
	char	*num_str;

	if (sp->precision < 0)
		num_str = ft_numtostr(va_arg(ap, int));
	else
		num_str = ft_numtostr_precision(va_arg(ap, int), sp->precision);
	if (sp->field_width >= 0)
	{
		if (sp->flags[(size_t)'-'] > 0)
			ft_padend(&num_str, (size_t)ft_abs(sp->field_width), ' ');
		else
			ft_padstart(&num_str, (size_t)sp->field_width, ' ');
	}
	return (num_str);
}
