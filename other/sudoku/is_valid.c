/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 22:22:37 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/28 09:49:32 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_valid(int ***sudoku, int n)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (sudoku[i][j][sudoku[i][j][0]] == 1)
				return (0);
			if (sudoku[i][j][0] != 0)
				count++;
			j++;
		}
		i++;
	}
	if (count < 17)
		return (0);
	return (1);
}
