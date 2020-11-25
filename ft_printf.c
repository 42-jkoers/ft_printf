/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:25:25 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/25 18:07:51 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

/*
** Returns length of all flags and percent (%-5d) --> 4
** Returns -1 on error
*/
size_t	do_special(char *percent, va_list ap, ssize_t *total_written)
{
	t_special	sp;
	size_t		conversion_len;

	conversion_len = set_special(&sp, ap, percent);
	if (sp.res == NULL)
		*total_written = -1;
	else if (write(FD, sp.res, sp.len) != (ssize_t)sp.len)
		*total_written = -1;
	else
		*total_written += (ssize_t)sp.len;
	if (sp.free)
		free(sp.res);
	return (conversion_len);
}

ssize_t	print(char *format, va_list ap)
{
	char		*percent;
	ssize_t		total_written;
	ssize_t		remainder;

	percent = ft_strchr(format, '%');
	total_written = 0;
	while (percent && total_written != -1)
	{
		if (percent - format > 0)
		{
			if (write(FD, format, percent - format) == -1)
				return (-1);
			total_written += percent - format;
		}
		format = percent + do_special(percent, ap, &total_written);
		if (total_written == -1)
			return (-1);
		percent = ft_strchr(format, '%');
	}
	remainder = ft_strlen(format);
	if (write(FD, format, remainder) != remainder)
		return (-1);
	return (total_written);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	ssize_t		len;

	va_start(ap, format);
	len = print((char *)format, ap);
	va_end(ap);
	return ((int)len);
}
