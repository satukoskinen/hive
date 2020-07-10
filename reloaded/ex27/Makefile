#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoskine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/02 17:53:24 by skoskine          #+#    #+#              #
#    Updated: 2020/06/02 18:34:08 by skoskine         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

objects = display_file.o ft_putchar.o ft_putstr.o
headers = fncs.h
binary = ft_display_file

all: ft_display_file

ft_display_file: $(objects)
	gcc -o $(binary) $(objects)

$(objects): $(headers)

clean:
	rm -f $(objects)

fclean: clean
	rm -f $(binary)

re: fclean all