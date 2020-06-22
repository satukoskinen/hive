# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/05 13:58:06 by skoskine          #+#    #+#              #
#    Updated: 2020/06/19 14:57:58 by skoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PART1_SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c \
ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c
PART2_SRCS = ft_itoa.c ft_memalloc.c ft_memdel.c ft_putchar_fd.c ft_putchar.c \
ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c \
ft_putstr.c ft_strclr.c ft_strdel.c ft_strequ.c ft_striter.c ft_striteri.c \
ft_strjoin.c ft_strmap.c ft_strmapi.c ft_strnequ.c ft_strnew.c ft_strsplit.c \
ft_strsub.c ft_strtrim.c
MEMS_SRCS = ft_bzero.c ft_memalloc.c ft_memmove.c ft_strcat.c ft_strchr.c \
ft_strcpy.c ft_strdup.c ft_strncat.c ft_strncpy.c ft_strnew.c
PUTS_SRCS = ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c \
ft_putstr_fd.c ft_putstr.c
LEN_SRCS = ft_strcat.c ft_strchr.c ft_strcpy.c ft_strdup.c ft_strjoin.c \
ft_strlcat.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncpy.c ft_strrchr.c \
ft_strtrim.c
STRSUB_SRCS = ft_strsplit.c ft_strtrim.c
PART1_TESTS = $(wildcard p1_tests/*.c)
PART2_TESTS = $(wildcard p2_tests/*.c)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

vpath %.c sources
vpath %.h includes

all: $(NAME)

$(NAME): $(PART1_SRCS) $(PART2_SRCS)
	$(CC) $(CFLAGS) -c $^
	ar rc $@ $(PART1_SRCS:.c=.o) $(PART2_SRCS:.c=.o)

$(MEMS_SRCS): mems.h

$(PUTS_SRCS): puts.h

$(LEN_SRCS): len.h

$(STRSUB_SRCS): strsub.h

clean:
	rm -f */*~ *~ *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

test_part1: $(NAME) $(PART1_TESTS)
#	norminette -R CheckForbiddenSourceHeader
	@$(CC) $(CFLAGS) -o $@ -L. -lft $(PART1_TESTS)
	./$@

test_part2: $(NAME) $(PART2_TESTS)
#	norminette -R CheckForbiddenSourceHeader
	@$(CC) $(CFLAGS) -o $@ -L. -lft $(PART2_TESTS)
	./$@

.PHONY: all re clean fclean