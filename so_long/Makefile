CC = gcc
CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
SRC = src/*.c
NAME = solong
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) so_long.c $(SRC) -o $@
bonus : $(NAME)
clean :
	rm -rf $(OBJS)
fclean :
	rm -rf $(NAME) $(OBJS)
re : fclean all



