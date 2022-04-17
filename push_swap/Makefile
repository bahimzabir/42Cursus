# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azabir <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 13:27:37 by azabir            #+#    #+#              #
#    Updated: 2022/03/27 13:27:55 by azabir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = src/*.c push_swap.c
SRCB = src/*.c bonus/*.c
NAME =  push_swap
BONUS = checker
OBJS = $(SRC:.c=.o)
OBJSB = $(SRCB:.c=.o)

all: $(NAME)

bonus : $(BONUS)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

$(BONUS) : $(SRCB)
	$(CC) $(CFLAGS) $(SRCB) -o $(BONUS)

clean :
	rm -rf $(OBJS) $(OBJSB)
fclean : clean
	rm -rf $(NAME) $(BONUS)
re : fclean all