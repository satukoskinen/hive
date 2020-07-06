/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 11:20:40 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/05 16:45:08 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		ret, i, fd;
	int		fds[argc];

	line = NULL;
	ret = 1;
	fd = 0;
	i = 1;
	if (argc == 1)
	{
//		printf("Reading from stdin:\n");
		while (ret == 1)
		{
			ret = get_next_line(fd, &line);
			printf("%s\n", line);
			free(line);
			line = NULL;

		}
	}	

	if (argc == 2)
	{
//		printf("Reading from argv[%d]:\n", i);
		fd = open(argv[i], O_RDONLY);
		while (ret == 1)
		{
			ret = get_next_line(fd, &line);
			printf("%s", line);
			if (ret == 1)
				printf("\n");
			free(line);
			line = NULL;

		}
		close(fd);
	}

	if (argc > 2)
	{
		while (i < argc)
		{
			fds[i] = open(argv[i], O_RDONLY);
			printf("fds %d %d\n", i, fds[i]);
			i++;
		}
		while (ret == 1)
		{
			for (int i = 1; i < argc; i++)
			{
				ret = get_next_line(fds[i], &line);
				printf("argv[%d]: $%s$\n", i, line);
//				if (ret == 1)
//					printf("\n");
				free(line);
				line = NULL;
			}
		}
	}
//*/
//	while (1)
//		;
	return (0);
}
