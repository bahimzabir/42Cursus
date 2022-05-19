CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread
SRC = philo.c src/*.c
SRCB = philo_bonus.c src/*.c
NAME = philo
BONUS = philo_bonus
OBJS = $(SRC:.c=.o)
OBJSB = $(SRCB:.c=.o)

all: $(NAME)
bonus: $(BONUS)
b : bonus

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

$(BONUS) : $(SRCB)
	$(CC) $(CFLAGS) $(SRCB) -pthread -o $(BONUS)

clean :
	rm -rf $(OBJS) $(OBJSB)
fclean : clean
	rm -rf $(NAME) $(BONUS)
re : fclean all
