/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:39:53 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/28 10:12:11 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sudoku.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int	ft_error(int message)
{
	if (message == 1)
		ft_putstr("error\n");
	else if (message == 2)
		ft_putstr("usage: ./sudoku input_file\n");
	else if (message == 3)
		ft_putstr("invalid input\n");
	return (EXIT_FAILURE);
}

int			main(int argc, char **argv)
{
	int		***sudoku;
	int		**solution;
	int		fd;
	int		n;
	int		i;
	
	if (argc != 2)
		return (ft_error(2));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error(1));
	if ((n = ft_read_input(fd, &sudoku)) == EXIT_FAILURE)
		return (ft_error(1));

	ft_update_sudoku(sudoku, n, 1);
	if (!(ft_is_valid(sudoku, n)))
		return (ft_error(3));

	if (!(solution = (int**)malloc(sizeof(int*) * n)))
		return (ft_error(1));
	i = 0;
	while (i < n)
	{
		if (!(solution[i++] = (int*)malloc(sizeof(int) * n)))
			return (ft_error(1));
	}

	if (ft_solve_sudoku(sudoku, solution, n) == 1)
	{
		ft_putstr("\nOutput:\n");
		ft_print_solution(solution, n);
		ft_free_array((void***)&solution, n);
		
		return (0);
	}
	else
	{
		ft_free_array((void***)&solution, n);
		return (ft_error(3));		
	}
}
