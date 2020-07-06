/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:30:58 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/06 15:59:59 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

/*
** Description of ft_delete_remainder
*/

static void	ft_delete_remainder(int fd, t_rlist **r_list)
{
	t_rlist	*p;
	t_rlist *temp;

	p = *r_list;
	if (p != 0 && p->next == NULL && p->fd == fd)
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

/*
** Description of ft_update_remainder
*/

static int	ft_update_remainder(int fd, char **input, t_rlist **r_list)
{
	t_rlist *p;
	t_rlist *prev;

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
	if ((p = (t_rlist*)malloc(sizeof(t_rlist))) == NULL)
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

/*
** Description of ft_add_input
*/

static char	*ft_add_input(int fd, char **input, char **line)
{
	char	*p;
	char	*ret;
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
	free(*input);
	*input = NULL;
	return (ret);
}

/*
** Description of ft_read_remainder
*/

static char	*ft_read_remainder(int fd, t_rlist *r_list, char **line)
{
	t_rlist *p;
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

/*
** Description of get_next_line
*/

int			get_next_line(const int fd, char **line)
{
	int				bytes_read;
	char			*buf;
	char			*rem;
	static t_rlist	*r_list;

	if (fd < 0 || line == NULL || (buf = ft_strnew(BUFF_SIZE + 1)) == NULL)
		return (-1);
	if (r_list != NULL && (rem = ft_read_remainder(fd, r_list, line)) != NULL)
	{
		free(buf);
		if (rem[0] != '\0')
			return (ft_update_remainder(fd, &rem, &r_list));
		free(rem);
		return (1);
	}
	bytes_read = read(fd, buf, BUFF_SIZE);
	buf[bytes_read] = '\0';
	if ((rem = ft_add_input(fd, &buf, line)) != NULL)
	{
		if (rem[0] != '\0')
			return (ft_update_remainder(fd, &rem, &r_list));
		free(rem);
		return (1);
	}
	if (bytes_read == BUFF_SIZE)
		return (get_next_line(fd, line));
	ft_delete_remainder(fd, &r_list);
	return (0);
}
