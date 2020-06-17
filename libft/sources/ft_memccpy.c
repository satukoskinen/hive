/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 21:16:16 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/15 13:49:16 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	void	*p;

	i = 0;
	p = dst;
	while (i < n)
	{
		((char*)dst)[i] = ((char*)src)[i];
		if (((char*)src)[i] == (unsigned char)c)
			return (++p);
		i++;
		p++;
	}
	return (NULL);
}
