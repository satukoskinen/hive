/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 09:01:22 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/03 16:21:29 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
{
	write(1,&c,1);
}

void	ft_putstr_and_newline(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int		main(int argc, char **argv)
{
	int printed[argc];
	int i;
	int j;
	int gr_i;

	i = 1;
	while (i < argc)
	{
		gr_i = i;
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[gr_i], argv[j]) > 0 && printed[j] != 1)
				gr_i = j;
			j++;
		}
		if (printed[gr_i] != 1)
		{
			ft_putstr_and_newline(argv[gr_i]);
			printed[gr_i] = 1;
		}
		if (gr_i == i)
			i++;
	}
	return (0);
}
