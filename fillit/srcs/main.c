/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 16:49:17 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/13 21:54:43 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

/*
**
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

	if (argc != 2)
		return (ft_exit_error());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_exit_error());
	tetriminos = (char**)malloc(sizeof(char*) * (26 + 1));
	if (tetriminos == NULL)
		return (ft_exit_error());
	if (ft_read_input(fd, tetriminos) == EXIT_FAILURE)
	{
		free(tetriminos);
		return (ft_exit_error());
	}
//	if (ft_check_input(tetriminos) == EXIT_FAILURE)
//		return (ft_exit_error());
	return (0);
}
