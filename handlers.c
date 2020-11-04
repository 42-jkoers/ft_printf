/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handlers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/04 13:43:40 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

char	*c_tostr(int c)
{
	char c1;

	c1 = c;
	return (ft_strndup(&c1, 1));
}

char	*s_tostr(char *s)
{
	if (s == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(s));
}

char	*p_tostr(void *p)
{
	return (ft_numtohexstr_u((unsigned long)p, true));
}

char	*i_tostr(long num)
{
	return (ft_numtostr(num));
}
