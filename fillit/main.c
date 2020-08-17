/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 16:49:17 by skoskine          #+#    #+#             */
/*   Updated: 2020/08/17 17:35:49 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

/*
** Prints an error message and returns EXIT_FAILURE for main to return.
*/

static int	ft_exit_foobar(void)
{
	ft_putstr("error\n");
	return (EXIT_FAILURE);
}

/*
** Prints a usage message and returns EXIT_FAILURE for main to return.
*/

static int	ft_exit_usage(void)
{
	ft_putstr("usage: ./fillit input_file\n");
	return (EXIT_FAILURE);
}

/*
** The program first checks that it has been given one file as argument
** that can be opened. The array in which to save the tetriminos is
** initialized, input is read from fd, and if it is valid it is saved
** in the array. The array is then passed on to ft_solve which returns the
** solution (minimum sized square that contains all the input tetriminos) that
** is saved and printed to standard output. Finally, remaining allocated
** memory is freed.
*/

int			main(int argc, char **argv)
{
	int		fd;
	int		square_size;
	int		i;
	t_mino	*tetriminos[26 + 1];

	if (argc != 2)
		return (ft_exit_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_exit_foobar());
	if (ft_read_input(fd, tetriminos) == EXIT_FAILURE)
		return (ft_exit_foobar());
	square_size = ft_fillit(tetriminos);
	i = 0;
	while (tetriminos[i] != NULL)
		free(tetriminos[i++]);
	if (square_size == 0)
		return (ft_exit_foobar());
	return (0);
}
