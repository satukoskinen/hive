/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:38:04 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/02 18:52:30 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INT_MAX 2147483647

int		ft_iterative_factorial(int nb)
{
	int result;

	result = 1;
	if (nb < 0)
		return (0);
	while (nb > 1)
	{
		if (result * 2 > INT_MAX - result)
			return (0);
		result *= nb;
		nb--;
	}
	return (result);
}
