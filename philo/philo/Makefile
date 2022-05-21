CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread
SRC = philo.c src/*.c
NAME = philo
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all
