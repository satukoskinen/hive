/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 16:42:53 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/02 18:51:12 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INT_MAX 2147483647

int		ft_recursive_factorial(int nb)
{
	int result;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	result = ft_recursive_factorial(nb - 1);
	if (result * 2 > INT_MAX - result)
		return (0);
	return (nb * result);
}
