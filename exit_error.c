/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_error.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 15:46:22 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/08 16:10:57 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

void	ft_exit_error(char *error_msg)
{
	ft_putstr(error_msg);
	exit(0);
}
