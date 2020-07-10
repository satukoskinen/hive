/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 21:30:16 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/30 13:50:43 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**	For ft_get_last_digit, this might have to be added:
**		if (n > 0 && base == 2)
**			digit[i++] = '0';
**		else if (n < 0 && base == 2)
**			digit[i++] = '1';
*/

static char	*ft_get_last_digit(char *digit, int n, int base)
{
	size_t	i;
	char	*base_digits;

	i = 0;
	base_digits = "0123456789ABCDEF";
	if (n < 0 && base == 10)
		digit[i++] = '-';
	digit[i] = base_digits[ft_abs(n)];
	digit[i + 1] = '\0';
	return (digit);
}

char		*ft_itoa_base(int n, int base)
{
	size_t	i;
	char	*base_digits;
	char	*digit;
	char	*next_digit;
	char	*final_str;

	i = 0;
	base_digits = "0123456789ABCDEF";
	if (base > 16)
		return (NULL);
	if (!(digit = (char*)malloc(sizeof(char) * 3)))
		return (NULL);
	if ((n >= 0 && n < base) || (n < 0 && n > -base))
		return (ft_get_last_digit(digit, n, base));
	digit[i] = base_digits[ft_abs(n % base)];
	digit[i + 1] = '\0';
	if (!(next_digit = ft_itoa_base(n / base, base)))
	{
		free(digit);
		return (NULL);
	}
	final_str = ft_strjoin(next_digit, digit);
	free(digit);
	free(next_digit);
	return (final_str);
}
