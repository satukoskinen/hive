/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:29:23 by skoskine          #+#    #+#             */
/*   Updated: 2020/08/17 17:12:08 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int ft_add(char *square, t_mino *mino, int size, int xy)
{
	int i;
	int j;
	int n;

	i = xy % size;
	j = xy / size;
	n = 1;
	while (n < 4)
	{
		if (!(j + mino->block[n].y < size && j + mino->block[n].y >= 0 &&
			  i + mino->block[n].x < size && i + mino->block[n].x >= 0 &&
			  square[size * (j + mino->block[n].y) + i + mino->block[n].x] == '.'))
			break;
		n++;
	}
	if (n == 4)
	{
		square[size * (j + mino->block[0].y) + i + mino->block[0].x] = mino->pos;
		square[size * (j + mino->block[1].y) + i + mino->block[1].x] = mino->pos;
		square[size * (j + mino->block[2].y) + i + mino->block[2].x] = mino->pos;
		square[size * (j + mino->block[3].y) + i + mino->block[3].x] = mino->pos;
		mino->added = 1;
		return (1);
	}
	return (0);
}

void ft_remove(char *square, int xy, int size, t_mino *mino)
{
	int n;
	int i;
	int j;

	n = 0;
	i = xy % size;
	j = xy / size;
	mino->added = 0;
	while (n < 4)
	{
		square[size * (j + mino->block[n].y) + i + mino->block[n].x] = '.';
		n++;
	}
}
