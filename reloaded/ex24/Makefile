#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoskine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/02 14:15:47 by skoskine          #+#    #+#              #
#    Updated: 2020/06/02 18:34:47 by skoskine         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

objects = srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_strcmp.o srcs/ft_strlen.o srcs/ft_swap.o
headers = $(wildcard includes/*.h)

all: libft.a

libft.a : $(objects)
	ar rc libft.a $(objects)

$(objects): $(headers)

clean:
	rm -f $(objects)

fclean: clean
	rm -f libft.a

re: fclean all
