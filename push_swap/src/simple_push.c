/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:41:52 by azabir            #+#    #+#             */
/*   Updated: 2022/04/04 16:42:12 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b2(t_list **sta, t_list **stb, int arc, int i)
{
	int	j;

	j = 9;
	while (i <= arc / 2 && !check_order(*sta))
	{
		if ((*sta)->index >= arc / 2 - i && (*sta)->index <= arc / 2 + i - 1)
			ft_pb(sta, stb);
		else if ((*sta)->index >= arc / 3 - i && (*sta)->index <= arc / 3)
			{
				ft_pb(sta, stb);
				ft_rb(stb);
			}
		else
			ft_ra(sta);
		if ((*stb) && (*stb)->index <= arc / 3)
			ft_rb(stb);
		if (!check_range(*sta, i, arc))
		{
			i = i + j;
		}
		if (i >= arc / 2)
				i = arc / 2;
	}
}

int	check_custom_range2(t_list *list, int a)
{
	 t_list	*temp;

	 temp = list;
	 while (temp)
	 {
		 if (temp->index >= a)
		 	return (1);
		temp = temp->next;
	 }
	 return (0);
}


void	push_to_a2(t_list **sta, t_list **stb, int arc)
{
	int	i;
	int	j;
	int	index;

	i = 1;
	j = 0;

	arc = 1;
	while (*stb)
		{
			if (check_order(*sta))
				index = (*sta)->index - 1;
			if ((*stb)->index == index || ((*stb)->index == index - 1 && check_order(*sta)))
			{
				ft_pa(sta, stb);
				if ((*sta)->index - (*sta)->next->index == 1)
					ft_sa(sta);
				i++;
			}
			else
				fast_move(stb, index, list_counter(*stb));
		}
}

void	simple_push(t_list **sta, t_list **stb, int arc)
{
	while (!(*stb) && !check_order(*sta))
	{
		push_to_b2 (sta, stb, arc, 10);
		push_to_a2(sta, stb, arc);
	}
}
