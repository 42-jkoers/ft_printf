/* ************************************************************************** */
/*																																						*/
/*																												::::::::						*/
/*	 ft_printf.c																				:+:		:+:						*/
/*																										 +:+										*/
/*	 By: jkoers <jkoers@student.codam.nl>						 +#+										 */
/*																									 +#+											*/
/*	 Created: 2020/11/03 01:14:55 by jkoers				#+#		#+#								 */
/*	 Updated: 2020/11/03 13:38:36 by jkoers				########	 odam.nl				 */
/*																																						*/
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
	else if (special[1] == 'd')
		return (d_tostr(va_arg(ap, long)));
	else if (special[1] == 'i')
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
	size_t len;

	len = 0;
	while (list != NULL)
	{
		len += ft_strlen((char *)(list->content));
		ft_putstr((char *)(list->content));
		list = list->next;
	}
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
	while (true)
	{
		special = ft_strchr(frmt, '%');
		if (special == NULL)
		{
			ft_lstpush_back(&list, ft_strdup(frmt));
			break ;
		}
		if (special - frmt > 0)
			ft_lstpush_back(&list, ft_strndup(frmt, (size_t)(special - frmt)));
		if (special[1] != '%')
		{
			ft_lstpush_back(&list, do_special(special, ap));
			frmt = special + 2;
		}
	}
	print_result(list);
	va_end(ap);
	return (0);
}
