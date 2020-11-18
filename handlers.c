/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handlers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/18 01:36:41 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

char	*c_tostr(int c)
{
	char c1;

	c1 = (char)c;
	return (ft_strndup(&c1, 1));
}

char	*s_tostr(t_special *sp, va_list ap)
{
	char	*s;
	char	*result;

	s = va_arg(ap, char *);
	if (s == NULL)
		result = ft_strdup("(null)");
	else if (sp->is0precision || sp->precision < 0)
		result = ft_strdup(s);
	else
		result = ft_strndup(s, sp->precision);
	if (sp->is0precision)
		sp->field_width = ft_max(sp->field_width, sp->precision);
	if (sp->field_width >= 0)
	{
		if (sp->flags[(size_t)'-'] > 0)
			ft_padend(&result, sp->field_width, ' ');
		else
			ft_padstart(&result, sp->field_width, ' ');
	}
	return (result);
}
