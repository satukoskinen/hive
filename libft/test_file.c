/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 17:17:34 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/06 13:51:00 by skoskine         ###   ########.fr       */
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
	str1 = ft_memset(str1, 64, 5);
	str1[5] = '\0';
	str2 = memset(str1, 64, 5);
	str1[5] = '\0';
	
	ft_putendl("ft_memset:");
	ft_putendl(str1);
    ft_putendl("memset:");
    ft_putendl(str2);
	return (0);
}

int		ft_test_bzero(void)
{
	return (0);
}

int		ft_test_memcpy(void)
{
	return (0);	
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
