/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handlers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/14 00:40:54 by jkoers        ########   odam.nl         */
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

char	*s_tostr(va_list ap, char *special)
{
	char	*s;
	long	min_width;
	long	min_precision;

	if (special[1] == 's')
		return (ft_strdup(va_arg(ap, char *)));
	min_width = get_min_width(ap, special, "s");
	min_precision = get_min_precision(ap, special, "s");
	s = va_arg(ap, char *);
	if (s == NULL)
		return (ft_strdup("(null)"));
	if (min_precision == -1 || min_precision == min_width)
		s = ft_strdup(s);
	else
		s = ft_strndup(s, (size_t)min_precision);
	if (min_width < 0)
		ft_padend(&s, (size_t)ft_abs(min_width), ' ');
	else
		ft_padstart(&s, (size_t)min_width, ' ');
	return (s);
}

char	*p_tostr(void *p)
{
	return (ft_numtohexstr_u((unsigned long)p, true, true));
}
