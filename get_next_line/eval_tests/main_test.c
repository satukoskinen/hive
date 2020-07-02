/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 11:20:40 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/02 08:40:11 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		ret, i, fd;
	int		fds[argc];

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

	i = 1;
	while (i < argc)
	{
		fds[i] = open(argv[i], O_RDONLY);
		i++;
	}
	ret = 1;
	while (ret != 0)
	{
		for (int i = 1; i < argc; i++)
		{
			ret = get_next_line(fds[i], &line);
			printf("argv[%d]: $%s$\n", i, line);
			free(line);
			line = NULL;
		}
	}

//	while (1)
//		;
	return (0);
}
