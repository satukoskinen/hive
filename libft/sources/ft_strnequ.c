/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 18:26:06 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/07 20:45:29 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] == '\0' && s2[i] == '\0' && i < n)
	{
		if (s1[i] != s2[i] && s1[i] + 32 != s2[i] && s1[i] - 32 != s2[i])
			return (0);
		i++;
		if (i < n && s1[i] != s2[i])
			return (0);
	}
	return (1);
}
