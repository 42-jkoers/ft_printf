/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   i_tostr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/10 15:03:21 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

char	*i_tostr(long num, char *special)
{
	char	*num_str;
	size_t	width;

	if (special[1] == 'i' || special[1] == 'd')
		num_str = ft_numtostr(num);
	else if (special[1] == '0')
	{
		width = (size_t)ft_strtonum_u(special + 2);
		num_str = ft_numtostr_pad(num, width);
	}
	else if (special[1] == '-' && ft_isdigit(special[2]))
	{
		num_str = ft_numtostr(num);
		width =  (size_t)ft_strtonum_u(special + 2);
		ft_padend(&num_str, width, ' ');
	}
	else if (ft_isdigit(special[1]))
	{
		num_str = ft_numtostr(num);
		width =  (size_t)ft_strtonum_u(special + 1);
		ft_padstart(&num_str, width, ' ');
	}
	else
		ft_exit_error("Not implamented 1");
	return (num_str);
}
