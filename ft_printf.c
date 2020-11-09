/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:25:25 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/08 23:24:30 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

bool	is_flag(char c)
{
	return (ft_includes("-0.* ", c));
}

char	*do_special(char conversion, char *special, va_list ap)
{
	if (conversion == 'c')
		return (c_tostr(va_arg(ap, int)));
	else if (conversion == 's')
		return (s_tostr(va_arg(ap, char *)));
	else if (conversion == 'p')
		return (p_tostr(va_arg(ap, void *)));
	else if (conversion == 'i' || conversion == 'd')
		return (i_tostr(va_arg(ap, long), special));
	else if (conversion == 'u')
		return (u_tostr(va_arg(ap, unsigned long)));
	else if (conversion == 'x')
		return (x_tostr(va_arg(ap, unsigned long)));
	else if (conversion == 'X')
		return (x_upper_tostr(va_arg(ap, unsigned long)));
	else
	{
		ft_exit_error("Not implamented 1");
		return (NULL);
	}
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
	// ft_lstclear(&list, &free);
	return ((int)len);
}


/*
** Returns length of special with all flags (%-5d) --> 4
*/
size_t	do_special_flags(t_list **list, char *special, va_list ap)
{
	size_t	special_len;
	char	*new_block;
	
	special_len = 1;
	while (is_flag(special[special_len])) // if instead of while?
		special_len++;
	while (ft_isdigit(special[special_len]))
		special_len++;
	new_block = do_special(special[special_len], special, ap);
	// NULL check?
	ft_lstpush_back(list, new_block);
	// printf("<%lu\n a>", special_len);
	return (special_len + 1);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*frmt;
	char	*special;
	t_list	*list;

	frmt = (char *)format;
	list = NULL;
	special = ft_strchr(frmt, '%');
	va_start(ap, format);
	while (special != NULL)
	{
		if (special - frmt > 0)
			ft_lstpush_back(&list, ft_strndup(frmt, (size_t)(special - frmt)));
		if (special[1] != '%')
			frmt = special + do_special_flags(&list, special, ap);
		special = ft_strchr(frmt, '%');
	}
	va_end(ap);
	ft_lstpush_back(&list, ft_strdup(frmt));
	return (print_result(list));
}
