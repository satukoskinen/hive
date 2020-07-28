/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sudoku.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 15:57:56 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/26 18:57:50 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_check_rows_and_cols(int ***sudoku, int i, int j, int n)
{
	int x;

	x = 0;
	while (x < n)
	{
		if (sudoku[i][x][0] != 0 && x != j)
			sudoku[i][j][sudoku[i][x][0]] = 1;
		if (sudoku[x][j][0] != 0 && x != i)
			sudoku[i][j][sudoku[x][j][0]] = 1;
		x++;
	}
}

static void	ft_check_box(int ***sudoku, int i, int j, int n)
{
	int box_dim;
	int box_i;
	int box_j;
	int x;
	int y;

	box_dim = ft_sqrt(n);
	box_i = (i / box_dim) * box_dim;
	box_j = (j / box_dim) * box_dim;
	y = box_i;
	while (y < box_i + box_dim)
	{
		x = box_j;
		while (x < box_j + box_dim)
		{
			if (sudoku[y][x][0] != 0 && y != i && x != j)
				sudoku[i][j][sudoku[y][x][0]] = 1;
			x++;
		}
		y++;
	}
}

void		ft_update_sudoku(int ***sudoku, int n, int all)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (all == 1 || sudoku[i][j][0] == 0)
			{
				ft_memset(&sudoku[i][j][1], 0, sizeof(int) * n);
				ft_check_rows_and_cols(sudoku, i, j, n);
				ft_check_box(sudoku, i, j, n);
			}
			j++;
		}
		i++;
	}
}
