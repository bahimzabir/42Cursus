# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azabir <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 18:40:07 by azabir            #+#    #+#              #
#    Updated: 2021/11/26 18:56:08 by azabir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_vprint.c ft_putstr_count.c ft_putchar_count.c \
ft_putnbr_count.c ft_putexa_count.c ft_putadd_count.c ft_putunbr_count.c

NAME = libftprintf.a
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $<
	ar rcs $(NAME) $@


clean :
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME) $(OBJS)

re : fclean all