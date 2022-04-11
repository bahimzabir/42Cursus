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
/*
void	simple_push(t_list **sta, t_list **stb, int arc)
{
	int		i;
	int		j;
	int		c;

	i = arc / 5;
	j = 1;
	c = 0;
	while (!(*stb) && !check_order(*sta))
	{
		while (check_order(*sta) == 0)
		{
			if ((*sta)->index <= i)
				ft_pb(sta, stb);
			else if(check_index(*sta, i))
				range_move(sta, i);
			if (j >= arc)
			{
				i = i + arc / 5;
				if (i >= arc)
					i = arc - 1;
				j = 0;
			}
			j++;
		}
		while (*stb)
		{
			if ((*sta)->index - (*stb)->index == 1)
				ft_pa(sta, stb);
			else
				fast_move(stb, sta, list_counter(*stb));
		}
	}
}*/

void	print_list3(t_list *tmp)
{
	printf("-----------------\n");
	if (tmp)
	{
		while (tmp)
		{
			printf("%d ", tmp->index);
			tmp = tmp->next;
		}
	}
	printf("\n-----------------\n");
}

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
			/*print_list2(*sta);
			printf("---- %d ----\n", index);
			print_list2(*stb);*/
			if ((*stb)->index == index || ((*stb)->index == index - 1 && check_order(*sta)))
			{
				ft_pa(sta, stb);
				if ((*sta)->index - (*sta)->next->index == 1)
					ft_sa(sta);
				i++;
			}
			else
			{
				//printf("---- HERE ----\n");
				fast_move(stb, index, list_counter(*stb));
			}
			/*if (i == 150)
			{
				while (list_end(*stb) >= 176)
					ft_rrb(stb);
				while (j <= 101)
				{
					if ((*stb) && (*stb)->index >= 200)
					{
						ft_pa(sta, stb);
						j++;
					}
					else
						ft_rb(stb);
					i++;
					if (!check_custom_range(*stb, 200))
						break;
				}
				while (!check_order(*sta))
					ft_pb(sta, stb);
			}*/
		}
}

void	simple_push(t_list **sta, t_list **stb, int arc)
{
		int		i;
	int		j;

	i = 30;
	j = 1;
	while (!(*stb) && !check_order(*sta))
	{
		push_to_b2 (sta, stb, arc, 10);
		push_to_a2(sta, stb, arc);
	}
}
