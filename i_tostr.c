/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   i_tostr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/22 22:38:44 by jkoers        ########   odam.nl         */
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
	long	numlen;

	if (sp->precision == 0 && i == 0)
		num_str = ft_strdup("");
	else 
	{
		if (sp->precision == -1 && sp->flag[(int)'0'])
			numlen = ft_max(sp->field_width - (i < 0 ? 1 : 0), 0); 
		else
			numlen = ft_max(sp->precision, 0);
		num_str = ft_numtostr_precision(i, (size_t)numlen);
	}
	apply_field_width(&num_str, sp);
	return (num_str);
}

char	*u_tostr(t_special *sp, unsigned long u)
{
	char	*num_str;
	size_t	numlen;

	if (sp->precision == 0 && u == 0)
		num_str = ft_strdup("");
	else 
	{
		if (sp->precision == -1 && sp->flag[(int)'0'])
			numlen = (size_t)ft_max(sp->field_width, 0); 
		else
			numlen = (size_t)ft_max(sp->precision, 0);
		num_str = ft_numtostr_precision_u(u, numlen);
	}
	apply_field_width(&num_str, sp);
	return (num_str);
}

char	*x_tostr(t_special *sp, unsigned long x, bool uppercase)
{
	char			*num_str;
	size_t	numlen;

	if (sp->precision == 0 && x == 0)
		num_str = ft_strdup("");
	else 
	{
		if (sp->precision == -1 && sp->flag[(int)'0'])
			numlen = (size_t)ft_max(sp->field_width, 0); 
		else
			numlen = (size_t)ft_max(sp->precision, 0);
		num_str = ft_numtohexstr_precision_u(x, !uppercase, false, numlen);
	}
	apply_field_width(&num_str, sp);
	return (num_str);
}

char	*p_tostr(t_special *sp, void *p)
{
	char			*num_str;
	size_t	numlen;

	if (p == 0)
	{
		// if (sp->precision >= (long)ft_strlen(P_NULL))
			num_str = ft_strdup(P_NULL);
		// else 
		// 	num_str = ft_strdup("");
	}
	else
	{
		if (sp->precision == -1 && sp->flag[(int)'0'])
			numlen = (size_t)ft_max(sp->field_width - 2, 0); 
		else
			numlen = (size_t)ft_max(sp->precision, 0);
		num_str = ft_numtohexstr_precision_u((unsigned long)p, true, true, numlen);
	}
	apply_field_width(&num_str, sp);
	return (num_str);
}
