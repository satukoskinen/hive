/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 21:30:16 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/30 09:54:15 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_itoa_base(int n, int base)
{
	size_t	i;
	char	*base_digits;
	char	*digit;

	base_digits = "0123456789ABCDEF";
	digit = (char*)malloc(sizeof(char) * 3);
	i = 0;
	if (base > 16)
		return (NULL);
	if ((n >= 0 && n < base) || (n < 0 && n > -base))
	{
/*
**		if (n > 0 && base == 2)
**			digit[i++] = '0';
**		else if (n < 0 && base == 2)
**			digit[i++] = '1';
*/
		if (n < 0 && base == 10)
			digit[i++] = '-';
		digit[i] = base_digits[ft_abs(n)];
		digit[i + 1] = '\0';
		return (digit);
	}
	digit[i] = base_digits[ft_abs(n % base)];
	digit[i + 1] = '\0';
	return (ft_strjoin(ft_itoa_base(n / base, base), digit));
}
