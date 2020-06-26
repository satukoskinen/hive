/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 12:34:55 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/05 13:37:38 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	void	*p;

	i = 0;
	p = b;
	while (i < len)
	{
		*(char*)p = (unsigned char)c;
		p++;
		i++;
	}
	return (b);
}
