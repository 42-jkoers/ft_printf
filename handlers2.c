/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handlers2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/03 14:16:48 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

char	*u_tostr(unsigned long u)
{
	return (ft_numtostr_u(u));
}

char	*x_tostr(unsigned long x)
{
	return (ft_numtohexstr_u(x, true));
}

char	*x_upper_tostr(unsigned long x_upper)
{
	return (ft_numtohexstr_u(x_upper, false));
}
