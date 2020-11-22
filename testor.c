/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testor.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 12:30:24 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/22 22:47:17 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "ft_printf.h"


int main(int argc, char const *argv[])
{
	printf("<%.*s>\n", 0, (char *)0);
	printf("<%.*s>\n", -2, (char *)0);
	printf("<%.*s>\n", 2, (char *)0);
	printf("<%0.2s>\n", (char *)0);
	
	printf("<%19s>\n", (char *)0);
	printf("<%19i>\n", 3);
	
	printf("<%0*.i>\n", -2, 10);
	printf("<%*.i>\n", -2, 10);
	printf("<%0*.i>\n", 2, 10);
	printf("<%*.i>\n", 2, 10);

	printf("<%0.*i>\n", -2, 10);
	printf("<%.*i>\n", -2, 10);
	printf("<%0.*i>\n", 2, 10);
	printf("<%.*i>\n", 2, 10);

	printf("<%*s>\n", 2, "he");
	
	printf("<%.*s>\n", 2, "joppe");

	printf("<%.*p>\n", 0, (void *)0);
	printf("<%.*p>\n", -2, (void *)0);
	printf("<%.*p>\n",  2, (void *)0);
	printf("<%0.2p>\n", (void *)0);
	printf("<%19p>\n", (void *)0);
	return 0;
}
