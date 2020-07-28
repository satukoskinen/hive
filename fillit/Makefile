# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 14:21:33 by skoskine          #+#    #+#              #
#    Updated: 2020/07/28 17:15:58 by skoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I libft/includes -g

HEADER = fillit.h

LIBFT = libft/libft.a

SRCS = main.c read_input.c solver.c compare.c add_remove.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

$(SRCS): $(HEADER)

$(LIBFT):
	$(MAKE) -C libft

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re