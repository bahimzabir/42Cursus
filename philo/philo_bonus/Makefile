CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread
SRC = philo.c src/*.c
SRCB = philo_bonus.c src/*.c
NAME = philo
BONUS = philo_bonus
OBJS = $(SRC:.c=.o)
OBJSB = $(SRCB:.c=.o)

all: $(BONUS)
bonus: $(BONUS)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

$(BONUS) : $(SRCB)
	$(CC) $(CFLAGS) $(SRCB) -pthread -o $(BONUS)

clean :
	rm -rf $(OBJSB) $(BONUS)
fclean : clean
	rm -rf $(BONUS)
re : fclean all
