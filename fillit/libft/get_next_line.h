/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 21:15:26 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/07 09:29:34 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 3

typedef struct		s_rlist
{
	int				fd;
	char			*remainder;
	struct s_rlist	*next;
}					t_rlist;

int					get_next_line(const int fd, char **line);

#endif
