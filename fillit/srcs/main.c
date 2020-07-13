/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 16:49:17 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/13 22:29:52 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

/*
** Prints an error message and returns EXIT_FAILURE for
** main to return.
*/

static int		ft_exit_error(void)
{
	ft_putstr("error\n");
	return (EXIT_FAILURE);
}

/*
** 
*/

int				main(int argc, char **argv)
{
	int		fd;
	char	**tetriminos;
	char	**result;
	
	result = NULL;
	if (argc != 2)
		return (ft_exit_error());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_exit_error());
	if (!(tetriminos = (char**)malloc(sizeof(char*) * (26 + 1))))
		return (ft_exit_error());
	if (ft_read_input(fd, tetriminos) == EXIT_FAILURE)
	{
		free(tetriminos);
		return (ft_exit_error());
	}
	result = ft_smallest_square(tetriminos);
	while (result != NULL && *result != 0)
	{
		ft_putendl(*result);
		result++;
	}
	return (0);
}
