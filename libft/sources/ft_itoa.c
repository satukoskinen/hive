/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 18:10:54 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/07 20:53:56 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int	ft_number_length(int n)
{
	int length;

	length = 1;
	if (n < 0)
		length++;
	while (n / 10 != 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

static char	ft_next_digit(int n, int i)
{
	int div;

	div = 1;
	while (i > 1)
	{
		div *= 10;
		i--;
	}
	return (n / div);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		length;

	i = 0;
	length = ft_number_length(n);
	if (!(str = malloc(sizeof(*str) * (length + 1))))
		return (NULL);
	if (n < 0)
	{
		str[i] = '-';
		i++;
	}
	while (i < length)
	{
		str[i] = ft_next_digit(n, length - i);
		i++;
	}
	str[i] = '\0';
	return (str);
}
