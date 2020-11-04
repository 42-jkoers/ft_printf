/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 02:19:33 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/03 14:39:18 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *format, ...);

char	*c_tostr(int c);
char	*s_tostr(char *s);
char	*p_tostr(void *p);
char	*p_tostr(void *p);
char	*d_tostr(long num);
char	*i_tostr(long num);
char	*u_tostr(unsigned long u);
char	*x_tostr(unsigned long x);
char	*x_upper_tostr(unsigned long x_upper);

#endif
