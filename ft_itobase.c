/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itobase.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/10/31 16:44:34 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>
#include "libft.h"




void	ft_putnbr_base(int64_t nbr, char *base)
{
	size_t	numlen;
	size_t	base_n;
	char	results[65];

	result_i = 0;
	base_n = ft_strlen(base);
	numlen = ft_numlen()
	while (1)
	{
		results[result_i] = base[nbr_cpy % base_n];
		nbr_cpy /= base_n;
		result_i++;
		if (nbr_cpy == 0)
			break ;
	}
	if (nbr < 0)
		write(1, "-", 1);
	while (result_i > 0)
	{
		write(1, results + result_i, 1);
		result_i--;
	}
}
