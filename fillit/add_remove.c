/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:29:23 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/28 15:01:26 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static int	ft_check(char **square, t_mino *mino, int i, int j)
{
	int	n;
	int	square_size;

	n = 1;
	square_size = 0;
	while (square[0][square_size] != '\0')
		square_size++;
	while (n < 4)
	{
		if (!(j + mino->block[n].y < square_size && j + mino->block[n].y >= 0 &&
			i + mino->block[n].x < square_size && i + mino->block[n].x >= 0 &&
			square[j + mino->block[n].y][i + mino->block[n].x] == '.'))
			break ;
		n++;
	}
	if (n == 4)
		return (1);
	return (0);
}

static int	ft_fill(char **square, t_mino *mino, int i, int j)
{
	square[j + mino->block[0].y][i + mino->block[0].x] = mino->pos;
	square[j + mino->block[1].y][i + mino->block[1].x] = mino->pos;
	square[j + mino->block[2].y][i + mino->block[2].x] = mino->pos;
	square[j + mino->block[3].y][i + mino->block[3].x] = mino->pos;
	mino->added = 1;
	return (1);
}

int			ft_add(char **square, t_mino *mino, int count)
{
	int	i;
	int	j;
	int ret;

	i = 0;
	j = 0;
	while (square[j] != NULL)
	{
		if (square[j][i] == '.')
		{
			if ((ret = ft_check(square, mino, i, j)) == 1 && count == 0)
				return (ft_fill(square, mino, i, j));
			else if (ret == 1 && count > 0)
				count--;
		}
		if (square[j][i] == '\0')
		{
			j++;
			i = 0;
		}
		else
			i++;
	}
	return (0);
}

void		ft_remove(char **square, t_mino *mino)
{
	int	i;
	int	j;
	int	n;

	j = 0;
	n = 0;
	while (square[j] != NULL && n <= 3)
	{
		i = 0;
		while (square[j][i] != '\0' && n <= 3)
		{
			if (square[j][i] == mino->pos)
			{
				square[j][i] = '.';
				n++;
			}
			i++;
		}
		j++;
	}
	mino->added = 0;
}
