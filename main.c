/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 01:14:55 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/04 01:21:52 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include <ft_printf.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	long a;

	a = 42;
	ft_printf("a%i", a);
	return (0);
}
