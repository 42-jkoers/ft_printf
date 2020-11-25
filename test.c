/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 01:29:45 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/24 01:25:07 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct		s_block
{
	char	*str;
	size_t	len;
	bool	free;
}					t_block;

t_block	setit(void)
{	
	return ({.str = strdup("ah"), .len = 2, .free = false});
}

int main(int argc, char const *argv[])
{
	t_block block;
	
	block = setit();
	printf("%lu\n", block.len);
	printf("%s\n", block.str);
}
