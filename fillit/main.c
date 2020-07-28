/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 16:49:17 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/28 17:30:22 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

#define ARR_SIZE 26

static int	ft_exit_foobar(void)
{
	ft_putstr("error\n");
	return (EXIT_FAILURE);
}

static int	ft_exit_usage(void)
{
	ft_putstr("usage: ./fillit input_file\n");
	return (EXIT_FAILURE);
}

static int	ft_arr_size(void **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_mino	**tetriminos;
	char	**result;

	if (argc != 2)
		return (ft_exit_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_exit_foobar());
	if (!(tetriminos = (t_mino**)malloc(sizeof(t_mino*) * (ARR_SIZE + 1))))
		return (ft_exit_foobar());
	if (ft_read_input(fd, tetriminos, ARR_SIZE) == EXIT_FAILURE)
	{
		free(tetriminos);
		return (ft_exit_foobar());
	}
	if (!(result = ft_fillit(tetriminos)))
	{
		ft_free_array((void***)&tetriminos, ft_arr_size((void**)tetriminos));
		return (ft_exit_foobar());
	}
	ft_free_array((void***)&tetriminos, ft_arr_size((void**)tetriminos));
	ft_print_array(result);
	ft_free_array((void***)&result, ft_arr_size((void**)result));
	return (0);
}
