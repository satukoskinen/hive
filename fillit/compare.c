/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:54:33 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/28 15:11:52 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_save(char **square, char **result)
{
	int	i;

	i = 0;
	while (square[i] != NULL)
	{
		ft_strcpy(result[i], square[i]);
		i++;
	}
	return (1);
}

static int	ft_is_empty(char **result)
{
	int	i;
	int	j;

	j = 0;
	while (result[j] != NULL)
	{
		i = 0;
		while (result[j][i] != '\0')
		{
			if (result[j][i] != '.')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int			ft_compare_and_save(char **square, char **result)
{
	int		i;
	int		j;
	char	c;

	if (ft_is_empty(result))
		return (ft_save(square, result));
	j = 0;
	c = 'A';
	while (square[j] != NULL)
	{
		i = 0;
		while (square[j][i] != '\0')
		{
			if (square[j][i] == c && result[j][i] != c)
				return (ft_save(square, result));
			else if (result[j][i] == c && square[j][i] != c)
				return (1);
			else if (result[j][i] == c && square[j][i] == c)
				c++;
			i++;
		}
		j++;
	}
	return (1);
}
