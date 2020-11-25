/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   i_tostr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/25 23:30:09 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void	i(t_special *sp, long i)
{
	long	numlen;

	if (sp->precision == 0 && i == 0)
	{
		sp->free = false;
		sp->len = 0;
	}
	else
	{
		if (sp->precision == -1 && sp->flag[(int)'0'])
			numlen = ft_max(sp->field_width - (i < 0 ? 1 : 0), 0);
		else
			numlen = ft_max(sp->precision, 0);
		sp->res = ft_numtostr_precision(i, (size_t)numlen);
		sp->len = ft_strlen(sp->res);
		sp->free = true;
	}
}

void	u(t_special *sp, unsigned long u)
{
	size_t	numlen;

	if (sp->precision == 0 && u == 0)
	{
		sp->len = 0;
		sp->free = false;
	}
	else
	{
		if (sp->precision == -1 && sp->flag[(int)'0'])
			numlen = (size_t)ft_max(sp->field_width, 0);
		else
			numlen = (size_t)ft_max(sp->precision, 0);
		sp->res = ft_numtostr_precision_u(u, numlen);
		sp->len = ft_strlen(sp->res);
		sp->free = true;
	}
}

void	x(t_special *sp, unsigned long x, bool uppercase)
{
	size_t	numlen;

	if (sp->precision == 0 && x == 0)
	{
		sp->len = 0;
		sp->free = false;
	}
	else
	{
		if (sp->precision == -1 && sp->flag[(int)'0'])
			numlen = (size_t)ft_max(sp->field_width, 0);
		else
			numlen = (size_t)ft_max(sp->precision, 0);
		sp->res = ft_numtohexstr_precision_u(x, !uppercase, false, numlen);
		sp->len = ft_strlen(sp->res);
		sp->free = true;
	}
}

void	p(t_special *sp, void *p)
{
	size_t	numlen;

	if (p == 0)
	{
		sp->res = P_NULL;
		sp->len = ft_strlen(P_NULL);
		sp->free = false;
	}
	else
	{
		if (sp->precision == -1 && sp->flag[(int)'0'])
			numlen = (size_t)ft_max(sp->field_width - 2, 0);
		else
			numlen = (size_t)ft_max(sp->precision, 0);
		sp->res = ft_numtohexstr_precision_u((unsigned long)p, 1, 1, numlen);
		sp->len = ft_strlen(sp->res);
		sp->free = true;
	}
}
