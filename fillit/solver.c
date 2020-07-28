/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 10:22:49 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/28 18:14:10 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static char	**ft_init_square(int square_size)
{
	char	**square;
	int		i;

	square = (char**)malloc(sizeof(char*) * (square_size + 1));
	if (!square)
		return (NULL);
	i = 0;
	while (i < square_size)
	{
		square[i] = (char*)malloc(sizeof(char) * (square_size + 1));
		if (!square[i])
			return (NULL);
		ft_memset(square[i], '.', square_size);
		square[i][square_size] = '\0';
		i++;
	}
	square[square_size] = NULL;
	return (square);
}

static int	ft_next_to_add(t_mino **minos, int i)
{
	while (minos[i] != NULL)
	{
		if (minos[i]->added == 0)
			return (i);
		i++;
	}
	return (i);
}

static int	ft_solve(t_mino **minos, char **result, char **square, int loop)
{
	int ret;
	int i;
	int c;
	int added;

	ret = 0;
	i = ft_next_to_add(minos, 0);
	if (minos[i] == NULL)
		return (ft_compare_and_save(square, result));
	while (minos[i] != NULL)
	{
		c = 0;
		if ((added = ft_add(square, minos[i], c)) == 0)
			return (0);
		while (added == 1)
		{
			ret = (ft_solve(minos, result, square, loop) == 1) ? 1 : ret;
			ft_remove(square, minos[i]);
			added = (loop == 0 || c > 1) ? 0 : ft_add(square, minos[i], ++c);
		}
		i = ft_next_to_add(minos, i + 1);
	}
	return (ret);
}

static int	ft_init_square_size(t_mino **minos)
{
	int size;
	int square_size;

	size = 0;
	while (minos[size] != NULL)
		size++;
		
	square_size = 2;
	while (square_size * square_size < size * 4)
		square_size++;
	return (square_size);
}

char		**ft_fillit(t_mino **minos)
{
	int		square_size;
	int		loop;
	char	**square;
	char	**result;

	square_size = ft_init_square_size(minos);
	loop = 0;
	if (!(square = ft_init_square(square_size)))
		return (NULL);
	if (!(result = ft_init_square(square_size)))
		return (NULL);
	while (ft_solve(minos, result, square, loop) != 1)
	{
		ft_free_array((void ***)&square, square_size);
		ft_free_array((void ***)&result, square_size);
		square_size = (loop == 0) ? square_size : square_size + 1;
		loop = (loop == 0) ? 1 : 0;
		if (!(square = ft_init_square(square_size)))
			return (NULL);
		if (!(result = ft_init_square(square_size)))
			return (NULL);
	}
	ft_free_array((void***)&square, square_size);
	return (result);
}
