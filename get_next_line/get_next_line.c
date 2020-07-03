/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 21:15:32 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/02 18:58:39 by skoskine         ###   ########.fr       */
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

void	ft_add_remainder(t_list **r_list, char *remainder, const int fd)
{
	fd_list	*new;

	if (*r_list == NULL)
		*r_list = ft_lstnew(NULL, sizeof(fd_list));
	if (!(new = (fd_list*)malloc(sizeof(fd_list))))
		return;
	new->fd = fd;
	new->remainder = remainder;
	ft_lstadd(r_list, ft_lstnew(new, sizeof(fd_list)));
}

fd_list	*ft_find_remainder(t_list *r_list, const int fd)
{
	while (r_list != 0)
	{
		if (((fd_list*)r_list->content)->fd == fd)
			return ((fd_list*)r_list->content);
		r_list = r_list->next;
	}
	return (NULL);
}

int		ft_check_remainder(fd_list *node, char **line)
{
	char	*p;
	char	*new_remainder;

	if (node == NULL || node->remainder == NULL)
		return (0);
	if ((p = ft_strchr(node->remainder, '\n')) != NULL)
	{
		*p = '\0';
		*line = ft_add_to_line(line, node->remainder);
		new_remainder = ft_strdup(p + 1);
		free(node->remainder);
		node->remainder = new_remainder;
		return (1);
	}
	else
	{
		*line = ft_add_to_line(line, node->remainder);
		free(node->remainder);
		node->remainder = NULL;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	ssize_t			ret;
	char			buf[BUFF_SIZE + 1];
	char			*p;
	static t_list	*r_list;

	if (fd < 0 || line == NULL || read(fd, buf, 0) == -1)
		return (-1);
	ft_memset(buf, 0, BUFF_SIZE + 1);
	if (ft_check_remainder(ft_find_remainder(r_list, fd), line) == 1)
		return (1);
	ret = read(fd, buf, BUFF_SIZE);
	if ((p = ft_strchr(buf, '\n')) != NULL)
	{
		*p = '\0';
		*line = ft_add_to_line(line, buf);
		ft_add_remainder(&r_list, ft_strdup(p + 1), fd);
		return (1);
	}
	*line = ft_add_to_line(line, buf);
	if (ret == BUFF_SIZE)
		return (get_next_line(fd, line));
	return (0);
}
