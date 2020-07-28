/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 10:02:58 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/28 10:05:36 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_array(void ***array, int size)
{
	int i;
	
	i = 0;
	if (array != NULL && *array != NULL)
	{
		while (i < size)
			free((*array)[i++]);
	}
	if (array != NULL)
		free(*array);	
}
