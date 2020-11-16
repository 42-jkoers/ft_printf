/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:25:25 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/16 14:04:52 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>

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

t_list	*format_to_list(char *format, va_list ap)
{
	char		*percent;
	t_list		*list;

	list = NULL;
	while (true)
	{
		percent = ft_strchr(format, '%');
		if (percent == NULL)
			break ;
		if (percent - format > 0)
			ft_lstpush_back(&list, ft_strndup(format, percent - format));
		if (percent[1] != '%')
			format = percent + do_special(&list, percent, ap);
	}
	ft_lstpush_back(&list, ft_strdup(format));
	return (list);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_list		*list;

	va_start(ap, format);
	list = format_to_list((char *)format, ap);
	va_end(ap);
	return (print_result(list));
}
