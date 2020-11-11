/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 02:19:33 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/11 18:40:46 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

void	ft_exit_error(char *error_msg);

int		ft_printf(const char *format, ...);

char	*c_tostr(int c);
char	*s_tostr(char *s);
char	*p_tostr(void *p);
char	*p_tostr(void *p);
char	*i_tostr(va_list ap, char *special);
char	*u_tostr(unsigned long u);
char	*x_tostr(unsigned long x);
char	*x_upper_tostr(unsigned long x_upper);
long	get_min_width(va_list ap, char *special, char *endchars);
long	get_min_precision(va_list ap, char *special, char *endchars);


#endif
