/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 21:15:26 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/03 18:58:21 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 3

typedef struct		r_list
{
	int				fd;
	char			*remainder;
	struct r_list	*next;
}					fd_list;

int				get_next_line(const int fd, char **line);

#endif
