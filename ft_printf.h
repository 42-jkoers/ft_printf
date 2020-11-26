/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 02:19:33 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/26 17:00:01 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>

# define S_NULL "(null)"
# ifdef __APPLE__
#  define P_NULL "0x"
# else
#  define P_NULL "(nil)"
# endif

int					ft_printf(const char *format, ...);

typedef	struct		s_special
{
	bool			flag[127];
	long			field_width;
	long			precision;
	char			*res;
	size_t			len;
	bool			free;
}					t_special;

size_t				set_special(t_special *sp, va_list ap, char *percent);
void				c(t_special *sp, int c);
void				s(t_special *sp, char *s);
void				i(t_special *sp, long i);
void				u(t_special *sp, unsigned long u);
void				x(t_special *sp, unsigned long x, bool uppercase);
void				p(t_special *sp, void *p);
void				invalid(t_special *sp, char *percent, char *format);

#endif
