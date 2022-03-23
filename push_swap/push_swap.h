# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h> 
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*prev;
	int				data;
	struct s_list	*next;
} t_list;

int		ft_atoi(char *s);
t_list	*lstmake(int data);
void lstaddback(t_list *stack_list, int data);



#endif