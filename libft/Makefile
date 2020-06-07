# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/05 13:58:06 by skoskine          #+#    #+#              #
#    Updated: 2020/06/07 13:50:33 by skoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
OBJECTS = ft_memset.o ft_bzero.o ft_strlen.o ft_putchar.o ft_putstr.o \
		ft_putendl.o ft_putnbr.o

FLAGS = -Wall -Wextra -Werror

vpath %.c sources

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

ft_memset.o: ft_memset.c $(HEADER)
	gcc -c $(FLAGS) ft_memset.c

ft_bzero.o: ft_bzero.c $(HEADER)
	gcc -c $(FLAGS) ft_bzero.c

ft_strlen.o: ft_strlen.c
	gcc -c $(FLAGS) ft_strlen.c

ft_putchar.o: ft_putchar.c
	gcc -c $(FLAGS) ft_putchar.c

ft_putstr.o: ft_putstr.c $(HEADER)
	gcc -c $(FLAGS) ft_putstr.c

ft_putendl.o: ft_putendl.c $(HEADER)
	gcc -c $(FLAGS) ft_putendl.c

ft_putnbr.o: ft_putnbr.c $(HEADER)
	gcc -c $(FLAGS) ft_putnbr.c

clean:
	rm -f *~ *~ *.o

fclean: clean
	rm -f $(NAME)

re: fclean all