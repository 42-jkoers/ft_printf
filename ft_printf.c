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

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*s;
	char	*format1;
	char	*special;
	t_list	*list;

	format1 = (char *)format;
	va_start(ap, 100);
	list = NULL;
	while (true)
	{
		special = ft_strchr(format1, '%');
		if (special)
		{
			if (special - format1 > 0)
			{
				ft_lstpush_back(&list, ft_strndup(format1, (size_t)(special - format1)));
				printf("<%s>\n", (char *)list->content);
			}
			if (special[1] == 'c')
				ft_lstpush_back(&list, c_tostr(va_arg(ap, int)));
			else if (special[1] == 's')
				ft_lstpush_back(&list, s_tostr(va_arg(ap, char *)));
			else if (special[1] == 'p')
				ft_lstpush_back(&list, p_tostr(va_arg(ap, void *)));
			else if (special[1] == 'd')
				ft_lstpush_back(&list, d_tostr(va_arg(ap, long)));
			else if (special[1] == 'i')
				ft_lstpush_back(&list, i_tostr(va_arg(ap, long)));
			else if (special[1] == 'u')
				ft_lstpush_back(&list, u_tostr(va_arg(ap, unsigned long)));
			else if (special[1] == 'x')
				ft_lstpush_back(&list, x_tostr(va_arg(ap, unsigned long)));
			else if (special[1] == 'X')
				ft_lstpush_back(&list, x_upper_tostr(va_arg(ap, unsigned long)));
			if (special[1] != '%')
				format1 = special + 2;
		}
		else
		{
			ft_lstpush_back(&list, ft_strdup(format1));
			break ;
		}
	}
	va_end(ap);
	while (list != NULL)
	{
		ft_putstr_fd((char *)(list->content), 1);
		list = list->next;
	}
	ft_putstr_fd("\n", 1);
	// ft_lstclear(&list, &free);
	return (42);
}
