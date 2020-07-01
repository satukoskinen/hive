/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 11:20:40 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/01 19:40:34 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		ret;
	int		i;
	int		fd;

	i = 1;
	fd = STDIN_FILENO;
	if (argc == 1)
	{
		printf("Reading from stdin:\n");
		ret = get_next_line(fd, &line);
		while (ret == 1)
		{
			printf("%d $%s$\n", ret, line);
			free(line);
			line = NULL;
			ret = get_next_line(fd, &line);
		}
		printf("%d $%s$\n", ret, line);
		free(line);
		line = NULL;
	}
	while (i < argc)
	{
		printf("Reading from argv[%d]:\n", i);
		fd = open(argv[i], O_RDONLY);
//		if (fd == -1)
//			printf("open failed\n");
		ret = get_next_line(fd, &line);
		while (ret == 1)
		{
			printf("%d $%s$\n", ret, line);
			free(line);
			line = NULL;
			ret = get_next_line(fd, &line);
		}
		printf("%d $%s$\n", ret, line);
		free(line);
		line = NULL;
		close(fd);
		i++;
	}
//	while (1)
//		;
	return (0);
}
