# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azabir <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 15:51:55 by azabir            #+#    #+#              #
#    Updated: 2021/12/22 15:52:00 by azabir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = src/*.c
NAME = client server

all : $(NAME)

bonus: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) server.c -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all


