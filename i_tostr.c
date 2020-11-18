/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   i_tostr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/18 01:36:41 by jkoers        ########   odam.nl         */
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

	num = (long)va_arg(ap, int);
	if (sp->precision == 0 && num == 0)
		num_str = ft_strdup("");
	else 
	{
		if (sp->is0precision && num < 0)
			sp->precision -= 1;
		sp->precision = ft_max(sp->precision, 0);
		num_str = ft_numtostr_precision(num, sp->precision);
	}
	if (sp->field_width >= 0)
	{
		if (sp->flags[(size_t)'-'] > 0)
			ft_padend(&num_str, sp->field_width, ' ');
		else
			ft_padstart(&num_str, sp->field_width, ' ');
	}
	return (num_str);
}

char	*u_tostr(t_special *sp, va_list ap)
{
	char			*num_str;
	unsigned long	num;
	long			precision;

	num = (unsigned long)va_arg(ap, int);
	if (sp->precision == 0 && num == 0)
		num_str = ft_strdup("");
	else 
	{
		sp->precision = ft_max(sp->precision, 0);
		num_str = ft_numtostr_precision_u(num, sp->precision);
	}
	if (sp->field_width >= 0)
	{
		if (sp->flags[(size_t)'-'] > 0)
			ft_padend(&num_str, sp->field_width, ' ');
		else
			ft_padstart(&num_str, sp->field_width, ' ');
	}
	return (num_str);
}

char	*x_tostr(t_special *sp, va_list ap, bool uppercase)
{
	char			*num_str;
	unsigned long	num;

	num = (unsigned int)va_arg(ap, unsigned int);
	if (sp->precision == 0 && num == 0)
		num_str = ft_strdup("");
	else 
	{
		sp->precision = ft_max(sp->precision, 0);
		num_str = ft_numtohexstr_precision_u(num, !uppercase, false, sp->precision);
	}
	if (sp->field_width >= 0)
	{
		if (sp->flags[(size_t)'-'] > 0)
			ft_padend(&num_str, sp->field_width, ' ');
		else
			ft_padstart(&num_str, sp->field_width, ' ');
	}
	return (num_str);
}

char	*p_tostr(t_special *sp, va_list ap)
{
	char			*num_str;
	unsigned long	num;

	num = (unsigned long)va_arg(ap, void *);
	if (num == 0)
		num_str = ft_strdup("(nil)");
	else
	{
		if (sp->is0precision)
			sp->precision -= 2;
		sp->precision = ft_max(sp->precision, 0);
		num_str = ft_numtohexstr_precision_u(num, true, true, sp->precision);
	}
	if (sp->field_width >= 0)
	{
		if (sp->flags[(size_t)'-'] > 0)
			ft_padend(&num_str, sp->field_width, ' ');
		else
			ft_padstart(&num_str, sp->field_width, ' ');
	}
	return (num_str);
}
