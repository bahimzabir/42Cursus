/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:14:38 by azabir            #+#    #+#             */
/*   Updated: 2022/03/24 16:14:41 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				index;
	struct s_list	*prev;
	int				data;
	struct s_list	*next;
}	t_list;

void	do_move(t_list **sta, t_list **stb, int arc, int i);
void	simple_push(t_list **sta, t_list **stb, int arc);
void	range_push(t_list **sta, t_list **stb, int arc);
void	basic_push(t_list **sta, t_list **stb, int arc);
void	fast_move(t_list **stb, int index, int c);
int		check_range(t_list *list, int i, int arc);
void	lstaddback(t_list *stack_list, int data);
void	swap_move(t_list **sta, t_list **stb);
void	ft_rrr(t_list **sta, t_list **stb);
void	ft_pa(t_list **sta, t_list **stb);
void	ft_pb(t_list **sta, t_list **stb);
void	ft_rr(t_list **sta, t_list **stb);
void	indexing(t_list **stack, int arc);
void	ft_ss(t_list **sta, t_list **stb);
int		check_index(t_list *list, int i);
void	range_move(t_list **sta, int i);
int		check_order(t_list	*stack);
int		list_counter(t_list *list);
int		ft_listlen(t_list *list);
int		list_end(t_list *list);
void	ft_sa(t_list **stack);
void	ft_sb(t_list **stack);
void	ft_rra(t_list **sta);
void	ft_rrb(t_list **stb);
void	ft_ra(t_list **sta);
void	ft_rb(t_list **stb);
t_list	*lstmake(int data);
int		ft_atoi(char *s);
void	ft_exit(void);

#endif