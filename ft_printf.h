/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 02:19:33 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/11 22:59:35 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
#include <stdbool.h>

void	ft_exit_error(char *error_msg);

int		ft_printf(const char *format, ...);

char	*c_tostr(int c);
char	*s_tostr(va_list ap, char *special);
char	*p_tostr(void *p);
char	*p_tostr(void *p);
char	*i_tostr(va_list ap, char *special);
char	*u_tostr(unsigned long u);
char	*x_tostr(va_list ap, char *special, bool lowercase);
long	get_min_width(va_list ap, char *special, char *endchars);
long	get_min_precision(va_list ap, char *special, char *endchars);


#endif
