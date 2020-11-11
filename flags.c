/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 18:39:47 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/11 22:05:44 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

/*
** Before the `.`
** Range:    long {MAX, MIN}
** Negative: padding right
** Positive: padding left
*/
long	get_min_width(va_list ap, char *special, char *endchars)
{
	size_t i;

	i = 0;
	while (!ft_includes(endchars, special[i]))
	{
		if (special[i] == '.')
			return (ft_strtonum(special + 1));
		i++;
	}
	if (special[1] == '0')
		special += 1;
	if (ft_includes("123456789-", special[1]))
	{
		if (special[2] == '*')
			return ((long)va_arg(ap, int));
		return (ft_strtonum(special + 1));
	}
	return (0);
}

/*
** After the `.`
** Range:  long {MAX, -1}
** Returns -1 if precision is undefined
*/
long	get_min_precision(va_list ap, char *special, char *endchars)
{
	size_t	i;
	long	precision;

	i = 0;
	while (!ft_includes(endchars, special[i]))
	{
		if (special[i] == '.')
		{
			if (special[i + 1] == '*')
				precision = (long)va_arg(ap, int);
			else
				precision = ft_strtonum(special + i + 1);
			return (precision < 0 ? -1 : precision);
		}
		i++;
	}
	// if (special[1] == '0')
	// {
	// 	if (special[2] == '*')
	// 		precision = (long)va_arg(ap, int);
	// 	else if (ft_includes(endchars, special[2]))
	// 		return (-1);
	// 	else
	// 		precision = ft_strtonum(special + 2);
	// 	return (precision < 0 ? -1 : precision);
	// }
	return (-1);
}
