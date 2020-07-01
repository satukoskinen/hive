/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 21:15:32 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/01 19:20:48 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
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

int		get_next_line(const int fd, char **line)
{
	ssize_t		ret;
	char		buf[BUFF_SIZE + 1];
	char		*p;
	char		*new_remainder;
	static char	*remainder;

	ft_memset(buf, 0, BUFF_SIZE + 1);
	if (fd < 0) /* invalid file descriptor */
		return (-1);
//	printf("line: $%s$\n", *line);
//	printf("remainder: $%s$\n", remainder);
	if (remainder != NULL) /* remainder has content from previous call of get_next_line */
	{
		if ((p = ft_strchr(remainder, '\n')) != NULL) /* '\n' found in remainder, add to line and reset remainder */
		{
			*p = '\0';
			*line = ft_add_to_line(line, remainder);
			new_remainder = ft_strdup(p + 1);
			free(remainder);
			remainder = new_remainder;
			return (1);
		}
		else /* add remainder to line before proceeding with reading */
		{
			*line = ft_add_to_line(line, remainder);
			free(remainder);
			remainder = NULL;
		}
	}
	ret = read(fd, buf, BUFF_SIZE);
	if (ret == -1)
		return (-1);
//	printf("ret %zd\n", ret);
//	printf("buf $%s$\n", buf);
	if ((p = ft_strchr(buf, '\n')) != NULL) /* '\n' reached */
	{
		*p = '\0';
		if (*(p + 1) != '\0')
			remainder = ft_strdup(p + 1);
		*line = ft_add_to_line(line, buf);
//		printf("return 1, line $%s$\n", *line);
		return (1);
	}
	else if (p == NULL && ret < BUFF_SIZE) /* EOF reached */
	{
		*line = ft_add_to_line(line, buf);
//		printf("return 0, line %s\n", *line);
		return (0);
	}
	else if (ret == BUFF_SIZE) /* buf does not contain '\n' or EOF */
	{
		*line = ft_add_to_line(line, buf);
		return (get_next_line(fd, line));
	}
	printf("return -1\n");
	return (-5);
}
