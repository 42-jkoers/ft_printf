/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   i_tostr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/16 21:49:40 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

long	get_precision_num(t_special *sp, bool num_is_negative)
{
	long precision;

	if (sp->precision >= 0)
		precision = sp->precision;
	else if (sp->precision0 >= 0)
		precision = num_is_negative ? ft_max(sp->precision0 - 1, 0) : sp->precision0;
	else
		precision = -1;
	return (precision);
}

char	*i_tostr(t_special *sp, va_list ap)
{
	char	*num_str;
	long	num;
	long	precision;

	num = (long)va_arg(ap, int);
	precision = get_precision_num(sp, num < 0);
	if (precision > 0)
		num_str = ft_numtostr_precision(num, precision);
	else if (precision == 0 && num == 0)
		num_str = ft_strdup("");
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

char	*u_tostr(t_special *sp, va_list ap)
{
	char			*num_str;
	unsigned long	num;
	long			precision;

	num = (unsigned long)va_arg(ap, int);
	precision = get_precision_num(sp, false);
	if (precision > 0)
		num_str = ft_numtostr_precision_u(num, precision);
	else if (precision == 0 && num == 0)
		num_str = ft_strdup("");
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

char	*x_tostr(t_special *sp, va_list ap, bool uppercase)
{
	char			*num_str;
	unsigned long	num;
	long			precision;

	num = (unsigned int)va_arg(ap, unsigned int);
	precision = get_precision_num(sp, false);
	if (precision > 0)
		num_str = ft_numtohexstr_precision_u(num, !uppercase, false, precision);
	else if (precision == 0 && num == 0)
		num_str = ft_strdup("");
	else
		num_str = ft_numtohexstr_u(num, !uppercase, false);
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
	char			*result;
	size_t			numlen;
	unsigned long	num;
	long			precision;

	num = (unsigned long)va_arg(ap, void *);
	precision = get_precision_num(sp, false);
	precision = sp->precision0 >= 0 ? sp->precision0 - 2 : sp->precision;
	if (num == 0)
		num_str = ft_strdup("(nil)");
	else
		num_str = ft_numtohexstr_precision_u(num, true, true, ft_max(precision, 0));
	numlen = ft_strlen(num_str);
	result = malloc(numlen + 3);
	result[0] = '<';
	ft_memcpy(result + 1, num_str, numlen);
	ft_memcpy(result + numlen + 1, ">\0", 2);
	if (sp->field_width >= 0)
	{
		if (sp->flags[(size_t)'-'] > 0)
			ft_padend(&num_str, sp->field_width, ' ');
		else
			ft_padstart(&num_str, sp->field_width, ' ');
	}
	return (num_str);
}
