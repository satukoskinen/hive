/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 13:32:51 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/05 16:24:55 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	if (size == 0)
		return (NULL);
	ptr = malloc(size);
	if (ptr != NULL)
		ft_memset(ptr, 0, size);
	return (ptr);
}
