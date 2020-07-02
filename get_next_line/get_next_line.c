/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 21:15:32 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/02 08:48:02 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
**	Returns a line (succession of characters that end with '\n' or EOF) read
**	from a file descriptor fd. Possible return values are 1 (line read),
**	0 (reading completed), and -1 (error occurred).
*/

char	*ft_add_to_line(char **line, char *content)
{
	char	*new;

	new = ft_strjoin(*line, content);
	if (*line != NULL)
		free(*line);
	return (new);
}

int		ft_check_remainder(char **remainder, char **line)
{
	char	*p;
	char	*new_remainder;

	if (*remainder == NULL || **remainder == '\0')
		return (0);
	if ((p = ft_strchr(*remainder, '\n')) != NULL)
	{
		*p = '\0';
		*line = ft_add_to_line(line, *remainder);
		new_remainder = ft_strdup(p + 1);
		free(*remainder);
		*remainder = new_remainder;
		return (1);
	}
	else
	{
		*line = ft_add_to_line(line, *remainder);
		free(*remainder);
		*remainder = NULL;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	ssize_t		ret;
	char		buf[BUFF_SIZE + 1];
	char		*p;
	static char	*remainder;

//	printf("line: $%s$\n", *line);
//	printf("rem: $%s$\n", remainder);
	ft_memset(buf, 0, BUFF_SIZE + 1);
	if (ft_check_remainder(&remainder, line) == 1)
		return (1);
	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	if ((p = ft_strchr(buf, '\n')) != NULL)
	{
		*p = '\0';
		*line = ft_add_to_line(line, buf);
		remainder = ft_strdup(p + 1);
		return (1);
	}
	*line = ft_add_to_line(line, buf);
	if (ret == BUFF_SIZE)
		return (get_next_line(fd, line));
	else
		return (0);
}
