/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   i_tostr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/11 18:38:00 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

long	get_min_width(va_list ap, char *special, char *endchars)
{
	size_t i;

	(void)(ap);
	i = 0;
	while (!ft_includes(endchars, special[i]))
	{
		if (special[i] == '.')
			return (ft_strtonum(special + 1));
		i++;
	}
	if (ft_includes("123456789-", special[1]))
		return (ft_strtonum(special + 1));
	return (0);
}


long	get_min_precision(va_list ap, char *special, char *endchars)
{
	size_t	i;
	long	precision;

	(void)(ap);

	i = 0;
	while (!ft_includes(endchars, special[i]))
	{
		if (special[i] == '.')
		{
			precision = ft_strtonum(special + i + 1);
			return (precision < 0 ? -1 : precision);
		}
		i++;
	}
	if (special[1] == '0')
	{
		precision = ft_strtonum(special + 2);
		return (precision < 0 ? -1 : precision);
	}
	return (-1);
}

char	*i_tostr(va_list ap, char *special)
{
	char	*num_str;
	long	min_width;
	long	min_precision;

	if (special[1] == 'i' || special[1] == 'd')
		return (ft_numtostr(va_arg(ap, int)));
	min_width = get_min_width(ap, special, "id");
	min_precision = get_min_precision(ap, special, "id");
	num_str = ft_numtostr_precision(va_arg(ap, int), min_precision == -1 ? 0 : min_precision);
	if (min_width < 0)
		ft_padend(&num_str, (size_t)ft_abs(min_width), ' ');
	else
		ft_padstart(&num_str, (size_t)min_width, ' ');

	return (num_str);
}
