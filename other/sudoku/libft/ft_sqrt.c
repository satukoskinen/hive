/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 21:20:43 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/25 21:39:27 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nbr)
{
	int sqrt;
	int div;

	sqrt = 1;
	div = 2;
	if (nbr == 1)
		return (sqrt);
	while (nbr / div > 10)
		div *= 2;
	while (nbr > 0 && sqrt <= nbr / div)
	{
		if (sqrt * sqrt == nbr)
			return (sqrt);
		sqrt++;
	}
	return (0);
}
