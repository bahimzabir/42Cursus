CC = gcc
CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
SRC = src/*.c so_long.c
NAME = solong

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

bonus : $(NAME)

clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all
