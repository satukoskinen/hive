/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:56:33 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/25 19:58:16 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/strsub.h"
#include "includes/len.h"

char	*ft_strtrim(char const *s)
{
	size_t		start;
	size_t		end;

	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	end = ft_strlen(s);
	while ((s[end] == '\0' || s[end] == ' ' ||
	s[end] == '\n' || s[end] == '\t') && end != start)
		end--;
	return (ft_strsub(s, start, end - start + 1));
}
