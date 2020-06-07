/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 12:57:04 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/06 10:36:07 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
size_t  ft_strlen(const char *s);

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void    ft_putendl(char const *s);
void    ft_putnbr(int n);

#endif
