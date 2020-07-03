/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:30:58 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/03 19:30:25 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static fd_list	*ft_fd_listnew(const int fd, char *input)
{
	fd_list	*new;

	new = (fd_list*)malloc(sizeof(fd_list));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->remainder = ft_strdup(input);
	new->next = NULL;
	return (new);
}

static int		ft_add_remainder(const int fd, char **input, fd_list **remainder)
{
	fd_list	*p;
	
	if (*remainder == NULL)
	{
		*remainder = ft_fd_listnew(fd, *input);
		free(*input);
		if (*remainder == NULL)
			return (-1);
		return (0);
	}
	p = *remainder;
	while (p != NULL)
	{
		if (p->fd == fd)
		{
			if (p->remainder != NULL)
			{
				free(p->remainder);
				p->remainder = NULL;
			}
			p->remainder = ft_strdup(*input);
			break;
		}
		p = p->next;
	}
	if (p == NULL)
		p = ft_fd_listnew(fd, *input);
	if (p == NULL)
		return (-1);
//	free(*input);
	return (0);
}

static int		ft_add_input(const int fd, char **input, fd_list **remainder, char **line)
{
	char	*p;
	char	*new;

	if ((p = ft_strchr(*input, '\n')) != NULL)
	{
		*p = '\0';
		new = ft_strjoin(*line, *input);
		free(*line);
		*line = new;
		p = ft_strdup(p + 1);
		if (ft_add_remainder(fd, &p, remainder) == -1)
			return (-1);
		return (1);
	}
	new = ft_strjoin(*line, *input);
	free(*line);
	*line = new;
	free(*input);
	return (0);
}

static int		ft_check_remainder(const int fd, fd_list **remainder, char **line)
{
	fd_list *p;

	if (*remainder == NULL)
		return (0);
	p = *remainder;
	while (p != NULL)
	{
		if (p->fd == fd && p->remainder != NULL)
			return (ft_add_input(fd, &(p->remainder), remainder, line));
		else
			p = p->next;
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	int				ret_value;
	char			*buf;
	static fd_list	*remainder;

//	if (remainder != NULL)
//		printf("rem now $%s$\n", remainder->remainder);
	if (fd < 0 || line == NULL || (buf = ft_strnew(BUFF_SIZE + 1)) == NULL)
		return (-1);
	if ((ret_value = ft_check_remainder(fd, &remainder, line)) == 1)
		return (1);
	if ((ret = read(fd, buf, BUFF_SIZE)) == 0)
		return (0);
	buf[ret] = '\0';
	if ((ret_value = ft_add_input(fd, &buf, &remainder, line)) == 1)
		return (1);
	else if (ret_value == 0 && ret == BUFF_SIZE)
		return (get_next_line(fd, line));
	else if (ret_value == 0 && ret < BUFF_SIZE)
	{

		return (0);
	}
	return (-1);
}
