/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 17:16:18 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/10 14:30:21 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/strsub.h"

static int	ft_count_strings(char const *s, char c)
{
	int string_count;
	int i;

	string_count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			string_count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (string_count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**strings;
	int		string_count;
	int		i;
	int		j;
	int		str_end;

	string_count = ft_count_strings(s, c);
	if (!(strings = (char**)malloc(sizeof(*strings) * (string_count + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < string_count)
	{
		while (s[i] == c)
			i++;
		str_end = i;
		while (s[str_end] != c && s[str_end] != '\0')
			str_end++;
		strings[j] = ft_strsub(s, i, str_end - i);
		j++;
	}
	strings[j] = 0;
	return (strings);
}
