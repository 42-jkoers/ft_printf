/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:25:25 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/04 14:44:37 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char	*do_special(char *special, va_list ap)
{
	if (special[1] == 'c')
		return (c_tostr(va_arg(ap, int)));
	else if (special[1] == 's')
		return (s_tostr(va_arg(ap, char *)));
	else if (special[1] == 'p')
		return (p_tostr(va_arg(ap, void *)));
	else if (special[1] == 'd' || special[1] == 'i')
		return (i_tostr(va_arg(ap, long)));
	else if (special[1] == 'u')
		return (u_tostr(va_arg(ap, unsigned long)));
	else if (special[1] == 'x')
		return (x_tostr(va_arg(ap, unsigned long)));
	else if (special[1] == 'X')
		return (x_upper_tostr(va_arg(ap, unsigned long)));
}

int		print_result(t_list *list)
{
	size_t	len;
	t_list	*current;

	len = 0;
	current = list;
	while (current != NULL)
	{
		len += ft_strlen((char *)(current->content));
		ft_putstr((char *)(current->content));
		current = current->next;
	}
	ft_lstclear(&list, &free);
	return ((int)len);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*s;
	char	*frmt;
	char	*special;
	t_list	*list;

	frmt = (char *)format;
	list = NULL;
	va_start(ap, format);
	special = ft_strchr(frmt, '%');
	while (special != NULL)
	{
		if (special - frmt > 0)
			ft_lstpush_back(&list, ft_strndup(frmt, (size_t)(special - frmt)));
		if (special[1] != '%')
		{
			ft_lstpush_back(&list, do_special(special, ap));
			frmt = special + 2;
		}
		special = ft_strchr(frmt, '%');
	}
	va_end(ap);
	ft_lstpush_back(&list, ft_strdup(frmt));
	return (print_result(list));
}
