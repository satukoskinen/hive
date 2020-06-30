/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:11:25 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/17 10:41:18 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/len.h"
#include "../includes/mems.h"
#include <string.h>

char	*ft_strcat(char *s1, const char *s2)
{
	size_t s1_len;
	size_t s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ft_memcpy(&s1[s1_len], s2, s2_len);
	s1[s1_len + s2_len] = '\0';
	return (s1);
}