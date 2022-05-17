CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread
SRC = philo_bonus.c src/*.c
NAME = philo
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(OBJS) $(OBJSB)
fclean : clean
	rm -rf $(NAME) $(BONUS)
re : fclean all
