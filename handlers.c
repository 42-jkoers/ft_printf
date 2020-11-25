/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handlers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/25 23:01:13 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

void	c(t_special *sp, int c)
{
	char	c1;

	c1 = (char)((unsigned char)c);
	sp->res = &c1;
	sp->len = 1;
	sp->free = false;
}

void	s(t_special *sp, char *s)
{
	sp->free = false;
	if (s == NULL)
	{	
		if (sp->precision != -1 && sp->precision < (long)ft_strlen(S_NULL))
			sp->len = 0;
		else
		{
			sp->res = S_NULL;
			sp->len = ft_strlen(S_NULL);
		}
		return ;
	}
	sp->res = s;
	sp->len = sp->precision == -1 ? ft_strlen(s) : (size_t)sp->precision;
}
