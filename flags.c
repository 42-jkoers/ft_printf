/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 18:39:47 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/16 17:05:13 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/*
** Returns length of conversion, 0 if it's not a conversion
*/
// size_t	is_conversion(char *str)
// {
// 	if (!ft_strcmp(str, "c"))
// 		return (1);
// 	if (!ft_strcmp(str, "s"))
// 		return (1);
// 	if (!ft_strcmp(str, "p"))
// 		return (1);
// 	if (!ft_strcmp(str, "i") || !ft_strcmp(str, "d"))
// 		return (1);
// 	if (!ft_strcmp(str, "u"))
// 		return (1);
// 	if (!ft_strcmp(str, "x") || !ft_strcmp(str, "X"))
// 		return (1);
// 	return (0);
// }

/*
** Before the `.`
** returns length of field_with in format string
*/
size_t	set_field_width(t_special *special, va_list ap, char *format)
{
	size_t i;

	i = 0;
	special->field_width = -1;
	if (ft_isdigit(format[0]))
		special->field_width = ft_strtonum(format);
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}

/*
** After the `.`
** returns length of precision in format string
*/
size_t	set_precision(t_special *special, va_list ap, char *format)
{
	size_t i;

	special->precision = -1;
	if (format[0] == '.')
		special->precision = ft_strtonum(format + 1);
	i = format[0] == '.' ? 1 : 0;	
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}

size_t	set_precision0(t_special *special, va_list ap, char *format)
{
	size_t i;

	special->precision0 = -1;
	if (special->flags[(size_t)'0'] == 0 || special->flags[(size_t)'-'] > 0)
		return (0);
	special->precision0 = ft_strtonum(format);
	i = 0;
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] == '.')
	{
		special->precision0 = -1;
		return (0);
	}
	return (i);
}

size_t	do_conversion(t_special *special, va_list ap, char *format, t_list **list)
{
	size_t	len;

	len = 1;
	if (format[0] == 'c')
		ft_lstpush_back(list, c_tostr(va_arg(ap, int)));
	else if (format[0] == 's')
		ft_lstpush_back(list, s_tostr(special, ap));
	else if (format[0] == 'p')
		ft_lstpush_back(list, p_tostr(va_arg(ap, void *)));
	else if (format[0] == 'i' || format[0] == 'd')
		ft_lstpush_back(list, i_tostr(special, ap));
	else if (format[0] == 'u')
		ft_lstpush_back(list, u_tostr(special, ap));
	else if (format[0] == 'x' || format[0] == 'X')
		ft_lstpush_back(list, x_tostr(special, ap));
	else
		ft_exit_error("Not implamented 0");
	return (len);
}

/*
** Returns length of all flags (%-5d) --> 4
*/
size_t	do_special(t_list **list, char *percent, va_list ap)
{
	t_special	special;
	size_t		i;
	const char	*flags = "0- +#";

	i = 1;
	ft_memset(special.flags, 0, sizeof(special.flags));
	while (ft_includes((char *)flags, percent[i]))
	{
		special.flags[(size_t)percent[i]] += 1;
		i++;
	}
	i += set_precision0(&special, ap, percent + i);
	i += set_field_width(&special, ap, percent + i);
	i += set_precision(&special, ap, percent + i);
	i += do_conversion(&special, ap, percent + i, list);
	return (i);
}
