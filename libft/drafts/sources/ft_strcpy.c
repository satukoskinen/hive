/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:48:14 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/10 14:24:29 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/len.h"
#include "../includes/mems.h"

char	*ft_strcpy(char *dst, const char *src)
{
	return (ft_memcpy(dst, src, ft_strlen(src) + 1));
}
