/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 02:19:33 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/25 23:32:58 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <unistd.h>
# include "../libft/include/libft.h"

# define S_NULL "(null)"
# define P_NULL "(nil)"
# define FD 1

void				ft_exit_error(char *error_msg);

typedef	struct		s_special
{
	bool			flag[127];
	long			field_width;
	long			precision;
	char			*res;
	size_t			len;
	bool			free;
}					t_special;

int					ft_printf(const char *format, ...);
ssize_t				print(char *format, va_list ap);
size_t				set_special(t_special *sp, va_list ap, char *percent);

void				c(t_special *sp, int c);
void				s(t_special *sp, char *s);
void				i(t_special *sp, long i);
void				u(t_special *sp, unsigned long u);
void				x(t_special *sp, unsigned long x, bool uppercase);
void				p(t_special *sp, void *p);

#endif
