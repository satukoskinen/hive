/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:54:27 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/17 09:56:37 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/len.h"
#include "../includes/mems.h"
#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t src_len;

	src_len = ft_strlen(src);
	if (src_len >= len)
		return (ft_memcpy(dst, src, len));
	ft_memcpy(dst, src, src_len);
	ft_memset(&dst[src_len], 0, len - src_len);
	return (dst);
}
