/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 16:29:34 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/02 17:52:16 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "fncs.h"

#define BUF_SIZE 10

int		main(int argc, char **argv)
{
	int		fd;
	int		read_bytes;
	char	buf[BUF_SIZE + 1];

	if (argc == 1)
		ft_putstr("File name missing.\n");
	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("Failed to open.");
			return (-1);
		}
		while ((read_bytes = read(fd, buf, BUF_SIZE)))
		{
			buf[read_bytes] = '\0';
			ft_putstr(buf);
		}
	}
	return (0);
}
