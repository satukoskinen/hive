/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:30:58 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/06 10:35:05 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
static void		ft_print_remainder(fd_list *r_list)
{
	fd_list *p;

	p = r_list;
	printf("print remainder\n");
	while (p != 0)
	{
		printf(" rem $%s$\n", p->remainder);
		p = p->next;
	}
}
*/

static void	ft_delete_remainder(int fd, fd_list **r_list)
{
	fd_list	*p;
	fd_list *temp;

	p = *r_list;
	if (p != 0 && p->remainder == NULL)
	{
		free(*r_list);
		*r_list = NULL;
	}
	else if (p != 0 && p->fd == fd)
	{
		*r_list = p->next;
		free(p);
	}
	else if (p != 0 && p->next != 0)
	{
		while (p->next->fd != fd)
			p = p->next;
		if (p->next->fd == fd)
		{
			temp = p->next->next;
			free(p->next);
			p->next = temp;
		}
	}
}

static int	ft_update_remainder(int fd, char **input, fd_list **r_list)
{
	fd_list *p;
	fd_list *prev;
	
	p = *r_list;
	prev = NULL;
	while (p != NULL)
	{
		if (p->fd == fd)
		{
			p->remainder = *input;
			return (1);
		}
		prev = p;
		p = p->next;
	}
	if ((p = (fd_list*)malloc(sizeof(fd_list))) == NULL)
		return (-1);
	p->fd = fd;
	p->remainder = *input;
	p->next = NULL;
	if (prev != NULL)
		prev->next = p;
	else
		*r_list = p;
	return (1);
}

static char	*ft_add_input(int fd, char **input, char **line)
{
	char	*p;
	char 	*ret;
	char	*new;

	ret = NULL;
	p = ft_strchr(*input, '\n');
	if (p != NULL)
	{
		*p = '\0';
		ret = ft_strdup(p + 1);
	}
	new = ft_strjoin(*line, *input);
	free(*line);
	*line = new;
//	printf("input %p $%s$\n", *input, *input);
//	printf("p %p $%s$\n", ret, ret);
	free(*input);
	*input = NULL;
	return (ret);
}

static char	*ft_read_remainder(int fd, fd_list *r_list, char **line)
{
	fd_list *p;
	char	*remainder;

	p = r_list;
	while (p != NULL)
	{
		if (p->fd == fd && p->remainder != NULL)
		{
			remainder = ft_add_input(fd, &(p->remainder), line);
			return (remainder);
		}
		p = p->next;
	}
	return (NULL);
}

int			get_next_line(const int fd, char **line)
{
	int				bytes_read;
	char			*buf;
	char			*remainder;
	static fd_list	*r_list;

	if (fd < 0 || line == NULL || (buf = ft_strnew(BUFF_SIZE + 1)) == NULL)
		return (-1);
	if (r_list != NULL && (remainder = ft_read_remainder(fd, r_list, line)) != NULL)
	{
		if (remainder[0] != '\0')
			return (ft_update_remainder(fd, &remainder, &r_list));
		free(remainder);
		return (1);
	}
	bytes_read = read(fd, buf, BUFF_SIZE);
	buf[bytes_read] = '\0';
	if ((remainder = ft_add_input(fd, &buf, line)) != NULL)
	{
		if (remainder[0] != '\0')
			return (ft_update_remainder(fd, &remainder, &r_list));
		free(remainder);
		return (1);
	}
	if (bytes_read == BUFF_SIZE)
		return (get_next_line(fd, line));
	ft_delete_remainder(fd, &r_list);
	return (0);
}
