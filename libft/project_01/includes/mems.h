/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mems.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:09:58 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/19 09:27:04 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMS_H
# define MEMS_H

# include <string.h>

void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);

#endif
