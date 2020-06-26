/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:54:05 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/25 18:37:04 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/space.h"

int			ft_atoi(const char *str)
{
	long int	i;
	int			sign;
	int			result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] < '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return ((int)(result * sign));
}
