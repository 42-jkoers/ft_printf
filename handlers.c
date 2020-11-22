/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handlers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/22 22:41:32 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

void	apply_field_width(char **str, t_special *sp)
{
	if (str == NULL || *str == NULL)
		return ;
	if (sp->field_width == -1)
		return ;
	if (sp->flag[(int)'-'])
		ft_padend(str, sp->field_width, ' ');
	else
		ft_padstart(str, sp->field_width, ' ');
}

char	*c_tostr(t_special *sp, int c)
{
	char	c1;
	char	*result;

	c1 = (char)((unsigned char)c);
	result = ft_strndup(&c1, 1);
	if (c1 != '%')
		apply_field_width(&result, sp);
	return (result);
}

char	*s_tostr(t_special *sp, char *s)
{
	char	*result;

	if (s == NULL)
	{	
		if (sp->precision != -1 && sp->precision < (long)ft_strlen(S_NULL))
			result = ft_strdup("");
		else 
			result = ft_strdup(S_NULL);
	}
	else if (sp->precision == -1)
		result = ft_strdup(s);
	else
		result = ft_strndup(s, sp->precision);
	apply_field_width(&result, sp);
	return (result);
}
