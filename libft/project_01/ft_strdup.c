/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:26:23 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/28 14:34:24 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if (!(s2 = ft_memalloc(ft_strlen(s1) + 1)))
		return (NULL);
	return (ft_memcpy(s2, s1, ft_strlen(s1) + 1));
}
