/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:44:14 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/28 10:09:58 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sudoku.h"
#include <stdlib.h>

static int	ft_count_availables(int *sudoku, int n)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while (i < n)
	{
		if (sudoku[i] == 0)
			count++;
		i++;
	}
	return (count);
}

static int	ft_next_to_add(int ***sudoku, int n, int coordinates[2])
{
	int count;
	int	lowest_count;
	int i;
	int j;

	lowest_count = n + 1;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (sudoku[i][j][0] == 0)
			{
				count = ft_count_availables(&sudoku[i][j][1], n);
				if (count == 1)
				{
					coordinates[0] = i;
					coordinates[1] = j;
					return (1);
				}
				else if (count == 0)
					return (-1);
				else if (count < lowest_count)
				{
					coordinates[0] = i;
					coordinates[1] = j;
					lowest_count = count;
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_empty_slots(int ***sudoku, int n)
{
	int i;
	int j;
	int empty;

	empty = 0;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (sudoku[i][j][0] == 0)
				empty++;
			j++;
		}
		i++;
	}
	return (empty);
}

static void	ft_save_sudoku(int ***sudoku, int **solution, int n)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			solution[i][j] = sudoku[i][j][0];
			j++;
		}
		i++;
	}
}

int			ft_solve_sudoku(int ***sudoku, int **solution, int n)
{
	int coordinates[2];
	int ret;
	int count;
	int i;

	count = 0;
	if (ft_empty_slots(sudoku, n) == 0)
	{
		ft_save_sudoku(sudoku, solution, n);
		return (1);
	}
	ret = ft_next_to_add(sudoku, n, coordinates);
	if (ret != -1)
	{
		i = 1;
		while (i <= n)
		{
			if (sudoku[coordinates[0]][coordinates[1]][i] == 0)
			{
				sudoku[coordinates[0]][coordinates[1]][0] = i;
				ft_update_sudoku(sudoku, n, 0);
				ret = ft_solve_sudoku(sudoku, solution, n);
				if (ret == 1)
					count++;
				if (count > 1)
					return (0);
				sudoku[coordinates[0]][coordinates[1]][0] = 0;
				ft_update_sudoku(sudoku, n, 0);
			}
			i++;
		}
	}
	return (count);
}
