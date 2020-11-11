/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   i_tostr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/11 22:46:10 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

char	*i_tostr(va_list ap, char *special)
{
	char	*num_str;
	long	min_width;
	long	min_precision;
	char	padding;

	if (special[1] == 'i' || special[1] == 'd')
		return (ft_numtostr(va_arg(ap, int)));
	min_width = get_min_width(ap, special, "id");
	min_precision = get_min_precision(ap, special, "id");
	num_str = ft_numtostr_precision(va_arg(ap, int), \
									min_precision == -1 ? 0 : min_precision);
	if (min_width < 0)
		ft_padend(&num_str, (size_t)ft_abs(min_width), ' ');
	else
	{
		padding = min_precision == -1 && special[1] == '0' ? '0' : ' ';
		ft_padstart(&num_str, (size_t)min_width, padding);
	}
	return (num_str);
}
