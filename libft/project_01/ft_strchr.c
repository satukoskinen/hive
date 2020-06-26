/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:48:31 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/24 16:56:55 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/len.h"
#include "includes/mems.h"

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}
