/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   i_tostr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/09 00:21:18 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

char	*i_tostr(long num, char *special)
{
	// fails if both 0 and - are passed
	char	*num_str;
	char	*temp;

	if (special[1] == '0')
	{
		// printf("%lu\n", ft_strtonum_u(special + 2));
		num_str = ft_numtostr_pad(num, (size_t)ft_strtonum_u(special + 2));
	}
	else if (special[1] == '-')
	{
		temp = ft_numtostr(num);
		num_str = ft_padend(temp, (size_t)ft_strtonum_u(special + 2), ' ');
		free(temp);
	}
	else if (special[1] == 'i' || special[1] == 'd')
		num_str = ft_numtostr(num);
	else
		ft_exit_error("Not implamented 1");
	return (num_str);
}
