/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 02:19:33 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/22 21:17:26 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include "../libft/include/libft.h"

# define S_NULL "(null)"
# define P_NULL "(nil)"

typedef	struct		s_special
{
	bool			flag[127];
	long			field_width;
	long			precision;
}					t_special;

void	ft_exit_error(char *error_msg);

int		ft_printf(const char *format, ...);
void	print_special(t_special *sp);

size_t	do_special(t_list **list, char *percent, va_list ap);
void	apply_field_width(char **str, t_special *sp);
char	*c_tostr(t_special *sp, int c);
char	*s_tostr(t_special *sp, char *s);
char	*p_tostr(t_special *sp, void *p);
char	*i_tostr(t_special *sp, long i);
char	*u_tostr(t_special *sp, unsigned long u);
char	*x_tostr(t_special *sp, unsigned long x, bool uppercase);

#endif
