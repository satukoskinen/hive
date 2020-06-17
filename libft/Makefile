# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/05 13:58:06 by skoskine          #+#    #+#              #
#    Updated: 2020/06/17 15:04:12 by skoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJECTS = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
ft_isdigit.o ft_isprint.o ft_itoa.o ft_memalloc.o \
ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o ft_memmove.o \
ft_memset.o ft_putchar_fd.o ft_putchar.o ft_putendl_fd.o ft_putendl.o \
ft_putnbr_fd.o ft_putnbr.o ft_putstr_fd.o ft_putstr.o ft_strcat.o ft_strchr.o \
ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o \
ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmap.o \
ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o \
ft_strnstr.o ft_strrchr.o ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o \
ft_toupper.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror

vpath %.c sources
vpath %.h includes

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

ft_bzero.o ft_memalloc.o ft_memmove.o ft_strcat.o ft_strchr.o ft_strcpy.o ft_strdup.o ft_strncat.o ft_strncpy.o ft_strnew.o: mems.h

ft_putendl_fd.o ft_putendl.o ft_putnbr_fd.o ft_putnbr.o ft_putstr_fd.o ft_putstr.o: puts.h

ft_strcat.o ft_strchr.o ft_strcpy.o ft_strdup.o ft_strjoin.o ft_strlcat.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncpy.o ft_strrchr.o ft_strtrim.o : len.h

ft_strsplit.o ft_strtrim.o : strsub.h

clean:
	rm -f */*~ *~ *.o

fclean: clean
	rm -f $(NAME)

re: fclean all