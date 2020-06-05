#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoskine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/05 13:58:06 by skoskine          #+#    #+#              #
#    Updated: 2020/06/05 15:16:52 by skoskine         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
HEADER = libft.h
SRC_PATH = sources/
OBJECTS = ft_memset.o ft_bzero.o ft_putchar.o ft_putstr.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

ft_memset.o: $(SRC_PATH)ft_memset.c $(HEADER)
	gcc -c $(FLAGS) $(SRC_PATH)ft_memset.c $(HEADER)

ft_bzero.o: $(SRC_PATH)ft_memset.c
	gcc -c $(FLAGS) $(SRC_PATH)ft_bzero.c

ft_putchar.o: $(SRC_PATH)ft_putchar.c
	gcc -c $(FLAGS) $(SRC_PATH)ft_putchar.c

ft_putstr.o: $(SRC_PATH)ft_putstr.c $(HEADER)
	gcc -c $(FLAGS) $(SRC_PATH)ft_putstr.c $(HEADER)

clean:
	rm -f *~ $(SRC_PATH)*~ *.o

fclean: clean
	rm -f $(NAME)

re: fclean all