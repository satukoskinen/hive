/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 13:21:09 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/22 16:00:45 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_print_board(char **board, int n)
{
	int	i;
	int j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
/*			if (board[i][j] == 'Q')
				ft_putchar('Q');
			else
				ft_putchar('.');
*/			ft_putchar(board[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_update_board(char **board, int i, int j, int n)
{
	int k;

	k = 0;
	while (k < n)
	{
		if (board[k][j] != 'Q')
			board[k][j] = 'X';
		if (board[i][k] != 'Q')
			board[i][k] = 'X';
		k++;
	}

}

char	**ft_add_queen(char **board, int n, int i, int j)
{
	board[i][j] = 'Q';
	ft_update_board(board, i, j, n);
	return (board);
}

void	ft_solve_queens(char **board, int q, int n)
{
	int i;
	int j;

	if (q == 0)
		ft_print_board(board, n);
	else
	{
		i = 0;
		while (i < n)
		{
			j = 0;
			while (j < n)
			{
				if (board[i][j] == '.')
				{
					ft_solve_queens(ft_add_queen(board, n, i, j), q - 1, n);
					break;
				}
				j++;
			}
			i++;
		}	
	}
}

int		main(int argc, char **argv)
{
	int		n;
	int		i;
	char	**board;

	if (argc != 2 || (n = ft_atoi(argv[1])) <= 0)
	{
		ft_putendl("Invalid argument.");
		return (1);
	}
	i = 0;
	board = (char**)malloc(sizeof(char*) * n);
	if (!board)
		return (1);
	while (i < n)
	{
		board[i] = (char*)malloc(sizeof(char) * (n + 1));
		if (!board[i])
			return (1);
		ft_memset(board[i], '.', n + 1);
		i++;
	}
	ft_solve_queens(board, n, n);
	return (0);
}
