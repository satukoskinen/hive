/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 13:22:01 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/02 13:38:29 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*range;
	int length;
	int i;

	if (min >= max)
		return (0);
	length = max - min;
	i = 0;
	if (length < 0)
		length = -length;
	range = malloc(sizeof(int) * length);
	while (i < length)
	{
		range[i] = min;
		i++;
		min++;
	}
	return (range);
}
