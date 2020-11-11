/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 18:39:47 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/11 18:40:01 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
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
