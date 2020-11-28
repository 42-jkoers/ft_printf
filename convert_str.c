/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_str.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/28 23:19:50 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

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
		sp->res = S_NULL;
		if (sp->precision != -1 && sp->precision < (long)ft_strlen(S_NULL))
			sp->len = 0;
		else
			sp->len = ft_strlen(S_NULL);
		return ;
	}
	sp->res = s;
	sp->len = ft_strlen(s);
	if (sp->precision != -1 && (long)sp->len > sp->precision)
		sp->len = (size_t)sp->precision;
}

void	invalid(t_special *sp, char *percent, char *format)
{
	sp->field_width = -1;
	sp->precision = -1;
	sp->res = percent;
	sp->len = (size_t)ft_max(format - percent, 0);
	if (format[0] != '\0')
		sp->len += 1;
	sp->free = false;
}
