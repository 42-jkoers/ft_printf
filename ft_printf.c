/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:25:25 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/26 13:15:03 by jkoers        ########   odam.nl         */
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

static ssize_t	write_result(t_special *sp, int fd)
{
	ssize_t written;
	long	padding;

	if (sp->res == NULL)
		return (-1);
	if (sp->len > 0 &&
		sp->flag[(int)'-'] &&
		write(fd, sp->res, sp->len) != (ssize_t)sp->len)
		return (-1);
	padding = ft_max(sp->field_width - sp->len, 0);
	written = (ssize_t)padding;
	while (padding > 0)
	{
		padding--;
		if (write(fd, " ", 1) != 1)
			return (-1);
	}
	if (sp->len > 0 &&
		!sp->flag[(int)'-'] &&
		write(fd, sp->res, sp->len) != (ssize_t)sp->len)
		return (-1);
	written += (ssize_t)sp->len;
	return (written);
}

/*
** Returns length of all flags and percent (%-5d) --> 4
** Returns -1 on error
*/

static size_t	do_special(char *percent, va_list ap, ssize_t *total, int fd)
{
	t_special	sp;
	size_t		conversion_len;
	ssize_t		written;

	sp.field_width = -1;
	sp.precision = -1;
	sp.res = NULL;
	sp.len = 0;
	sp.free = false;
	conversion_len = set_special(&sp, ap, percent);
	if (sp.res == NULL)
	{
		*total = -1;
		return (0);
	}
	written = write_result(&sp, fd);
	if (written == -1)
		*total = -1;
	else
		*total += (ssize_t)sp.len;
	if (sp.free)
		free(sp.res);
	return (conversion_len);
}

static ssize_t	print(char *format, va_list ap, int fd)
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
			if (write(fd, format, percent - format) != percent - format)
				return (-1);
			total_written += percent - format;
		}
		format = percent + do_special(percent, ap, &total_written, fd);
		percent = ft_strchr(format, '%');
	}
	remainder = ft_strlen(format);
	if (write(fd, format, remainder) != remainder)
		return (-1);
	return (total_written);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	ssize_t		len;

	va_start(ap, format);
	len = print((char *)format, ap, 1);
	va_end(ap);
	return ((int)len);
}
