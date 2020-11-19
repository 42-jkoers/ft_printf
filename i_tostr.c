/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   i_tostr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/19 00:20:08 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

char	*i_tostr(t_special *sp, long i)
{
	char	*num_str;

	if (sp->precision == 0 && i == 0)
		num_str = ft_strdup("");
	else 
	{
		if (sp->is0precision && i < 0)
			sp->precision -= 1;
		sp->precision = ft_max(sp->precision, 0);
		num_str = ft_numtostr_precision(i, sp->precision);
	}
	apply_field_width(&num_str, sp);
	return (num_str);
}

char	*u_tostr(t_special *sp, unsigned long u)
{
	char	*num_str;

	if (sp->precision == 0 && u == 0)
		num_str = ft_strdup("");
	else 
	{
		sp->precision = ft_max(sp->precision, 0);
		num_str = ft_numtostr_precision_u(u, sp->precision);
	}
	apply_field_width(&num_str, sp);
	return (num_str);
}

char	*x_tostr(t_special *sp, unsigned long x, bool uppercase)
{
	char			*num_str;

	if (sp->precision == 0 && x == 0)
		num_str = ft_strdup("");
	else 
	{
		sp->precision = ft_max(sp->precision, 0);
		num_str = ft_numtohexstr_precision_u(x, !uppercase, false, sp->precision);
	}
	apply_field_width(&num_str, sp);
	return (num_str);
}

char	*p_tostr(t_special *sp, void *p)
{
	char			*num_str;

	if (p == 0)
	{
		num_str = ft_strdup("(nil)");
		if (sp->precision > 0 && sp->is0precision && sp->field_width < 0)
			sp->field_width = sp->precision;
	}
	else
	{
		if (sp->is0precision)
			sp->precision -= 2;
		sp->precision = ft_max(sp->precision, 0);
		num_str = ft_numtohexstr_precision_u((unsigned long)p, true, true, sp->precision);
	}
	apply_field_width(&num_str, sp);
	return (num_str);
}
