/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 17:17:34 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/05 18:17:12 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

int		ft_test_memset(void)
{
	char *str1;
	char *str2;

	if (!(str1 = (char*)malloc(sizeof(char) * 6)))
		return (-1);
    if (!(str2 = (char*)malloc(sizeof(char) * 6)))
        return (-1);
	ft_putstr("ft_memset: \n");
	ft_putstr(ft_memset(str1, 64, 6));
	ft_putchar('\n');
    ft_putstr("memset: \n");
    ft_putstr(memset(str1, 64, 6));
	ft_putchar('\n');
	return (0);
}

int		ft_test_memcpy(void)
{
	
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (strcmp(argv[1], "memset") == 0)
			ft_test_memset();
	}
	return (0);
}
