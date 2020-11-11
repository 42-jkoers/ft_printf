/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handlers2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/12 00:13:44 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdbool.h>
#include <stdarg.h>

char	*u_tostr(unsigned long u)
{
	return (ft_numtostr_u(u));
}

char	*x_tostr(va_list ap, char *special, bool lowercase)
{
	char	*num_str;
	long	min_width;
	long	min_precision;
	char	padding;

	if (special[1] == 'x' || special[1] == 'X')
		return (ft_numtohexstr_u(va_arg(ap, unsigned int), lowercase, false));
	min_width = get_min_width(ap, special, "xX");
	min_precision = get_min_precision(ap, special, "xX");
	num_str = ft_numtohexstr_precision_u(va_arg(ap, unsigned int), lowercase, \
	false, min_precision == -1 ? 0 : min_precision);
	if (min_width < 0)
		ft_padend(&num_str, (size_t)ft_abs(min_width), ' ');
	else
	{
		padding = min_precision == -1 && special[1] == '0' ? '0' : ' ';
		ft_padstart(&num_str, (size_t)min_width, padding);
	}
	return (num_str);
}
