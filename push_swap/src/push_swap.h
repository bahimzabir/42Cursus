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
# include <stdio.h> 
# include <unistd.h>

typedef struct s_list
{

	int				index;
	struct s_list	*prev;
	int				data;
	struct s_list	*next;
}	t_list;

void	lstaddback(t_list *stack_list, int data);
void	ft_rrr(t_list **sta, t_list **stb);
void	ft_pa(t_list **sta, t_list **stb);
void	ft_pb(t_list **sta, t_list **stb);
void	ft_rr(t_list **sta, t_list **stb);
void	indexing(t_list **stack, int arc);
void	ft_ss(t_list **sta, t_list **stb);
void	do_move(t_list **sta, int arc, int i);
int		check_order(t_list	*stack);
int		ft_listlen(t_list *list);
void	ft_sa(t_list **stack);
void	ft_sb(t_list **stack);
void	ft_rra(t_list **sta);
void	ft_rrb(t_list **stb);
void	ft_ra(t_list **sta);
void	ft_rb(t_list **stb);
t_list	*lstmake(int data);
int		ft_atoi(char *s);

#endif