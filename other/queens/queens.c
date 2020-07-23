/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 13:21:09 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/23 09:57:29 by skoskine         ###   ########.fr       */
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
			ft_putchar(board[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

int		ft_available_square(char **board, int i, int j, int n)
{
	int k;

	k = 0;
	while (k < n)
	{
		if (board[k][j] == 'Q' || board[i][k] == 'Q')
			return (0);
		k++;
	}
	k = 1;
	while (i - k >= 0 || i + k < n)
	{
		if (i - k >= 0 && j - k >= 0 && board[i - k][j - k] == 'Q')
			return (0);
		if (i - k >= 0 && j + k < n && board[i - k][j + k] == 'Q')
			return (0);
		if (i + k < n && j - k >= 0 && board[i + k][j - k] == 'Q')
			return (0);
		if (i + k < n && j + k < n && board[i + k][j + k] == 'Q')
			return (0);
		k++;
	}
	return (1);
}

void	ft_solve_queens(char **board, int i, int n)
{
	int j;

	if (i == n)
		ft_print_board(board, n);
	else
	{
		j = 0;
		while (j < n)
		{
			if (ft_available_square(board, i, j, n) == 1)
			{
				board[i][j] = 'Q';
				ft_solve_queens(board, i + 1, n);
				board[i][j] = '.';
			}
			j++;
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
	ft_solve_queens(board, 0, n);
	return (0);
}
