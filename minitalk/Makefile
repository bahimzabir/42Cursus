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
NAME = server
CLIENT = client
OBJC = (client.c = client.o)
all : $(NAME) $(CLIENT)

bonus: $(NAME) $(CLIENT)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) server.c -o $@
$(CLIENT):
	$(CC) $(CFLAGS) $(SRC) client.c -o $@

clean:
	rm -rf $(NAME) $(CLIENT)

fclean: clean

re: fclean all


