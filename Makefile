# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mudanaci <mudanaci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 13:56:13 by mudanaci          #+#    #+#              #
#    Updated: 2023/02/17 14:25:56 by mudanaci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

list = ft_printf.c \
		ft_source.c


OBJS = $(list:.c=.o)

CC = gcc
CFLAGS = -c -Wall -Werror -Wextra
HEADER = ft_printf.h
NAME = libftprintf.a

all: $(NAME)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) $<

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re