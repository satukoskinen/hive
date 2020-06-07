# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/05 13:58:06 by skoskine          #+#    #+#              #
#    Updated: 2020/06/07 21:36:54 by skoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
OBJECTS = ft_bzero.o ft_itoa.o ft_memalloc.o ft_memccpy.o ft_memcpy.o \
ft_memdel.o \
ft_memset.o ft_putchar_fd.o ft_putchar.o ft_putendl_fd.o ft_putendl.o \
ft_putnbr_fd.o ft_putnbr.o ft_putstr_fd.o ft_putstr.o ft_strclr.o ft_strdel.o \
ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlen.o ft_strmap.o \
ft_strmapi.o ft_strnequ.o ft_strnew.o ft_strsplit.o ft_strsub.o ft_strtrim.o
OBJ_HEADER = ft_bzero.o ft_memalloc.o ft_putendl_fd.o ft_putendl.o \
ft_putnbr_fd.o ft_putnbr.o ft_putstr_fd.o ft_putstr.o ft_strdel.o ft_strjoin.o \
ft_strmap.o ft_strmapi.o ft_strnew.o ft_strsplit.o ft_strtrim.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror

vpath %.c sources

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

$(OBJ_HEADER): $(HEADER)

clean:
	rm -f *~ *~ *.o

fclean: clean
	rm -f $(NAME)

re: fclean all