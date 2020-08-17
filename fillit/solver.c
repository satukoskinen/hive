/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 10:22:49 by skoskine          #+#    #+#             */
/*   Updated: 2020/08/17 17:40:52 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int	ft_print_square(char *result, int square_size)
{
	int j;
	int i;

	j = 0;
	while (j < square_size)
	{
		i = 0;
		while (i < square_size)
		{
			ft_putchar(result[square_size * j + i]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
	return (1);
}

/*
** Ft_solver implements a backtracking algorithm to find (almost) all possible
** arrangements of all given tetriminos in the given square. If it encounters
** the stopping condition (all minos have already been added), it calls
** ft_compare_and_save to compare with possible previously found solution and
** if its arrangement is preferable to the previous result, that is replaced.
** If loop is set to one on the function call, ft_solve
*/

static int	ft_solve(t_mino **minos, int i, char *sqr, int size)
{
	int xy;

	if (minos[i] == NULL)
		return (ft_print_square(sqr, size));
	xy = 0;
	while (sqr[xy] != 0)
	{
		if (sqr[xy] == '.' && ft_add(sqr, minos[i], size, xy) == 1)
		{
			if ((ft_solve(minos, i + 1, sqr, size)) == 1)
				return (1);
			ft_remove(sqr, xy, size, minos[i]);
		}
		xy++;
	}
	return (0);
}

/*
** Initializes the array of pointers to char arrays for the square
** in which tetriminos are placed. The outer array of pointers is
** terminated by a NULL pointer.
*/

static char	*ft_init_square(int square_size)
{
	char	*square;

	square = (char*)malloc(sizeof(char) * (square_size * square_size + 1));
	if (!square)
		return (NULL);
	ft_memset(square, '.', square_size * square_size);
	square[square_size * square_size] = '\0';
	return (square);
}

/*
** After calculating the starting size of the square and initializing the square
** and result arrays, ft_solve is called until it finds a solution. If no
** solution is found, ft_solve is first called with an additional loop that
** tries out up to 3 possible positions for each added block. If that does not
** return a solution, the square size is increased. Finally, the square array
** is freed and the result array is returned.
*/

int			ft_fillit(t_mino **minos)
{
	int		size;
	int		square_size;
	char	*square;

	size = 0;
	while (minos[size] != NULL)
		size++;
	square_size = 2;
	while (square_size * square_size < size * 4)
		square_size++;
	if (!(square = ft_init_square(square_size)))
		return (0);
	while (ft_solve(minos, 0, square, square_size) != 1)
	{
		free(square);
		square_size++;
		if (!(square = ft_init_square(square_size)))
			return (0);
	}
	free(square);
	return (square_size);
}
