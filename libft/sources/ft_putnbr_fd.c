/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 18:52:09 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/07 19:29:35 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int div;

	div = 1;
	while (n / div >= 10)
		div *= 10;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (div > 1)
		ft_putnbr_fd(n % div, fd);
	ft_putchar_fd(n / div + 48, fd);
}
