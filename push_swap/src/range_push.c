/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:46:07 by azabir            #+#    #+#             */
/*   Updated: 2022/04/04 16:46:44 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list2(t_list *tmp)
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

void	push_to_b(t_list **sta, t_list **stb, int arc, int i)
{
	int	j;

	j = 22;
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

int	check_custom_range(t_list *list, int a)
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


void	push_to_a(t_list **sta, t_list **stb, int arc)
{
	int	i;
	int	j;

	i = 1;
	j = 0;

	arc = 1;
	while (*stb)
		{
			if ((*sta)->index - (*stb)->index == 1 /*|| ((*sta)->index - (*stb)->next->index == 2 && check_order(*sta))*/)
			{
				ft_pa(sta, stb);
				if ((*sta)->index - (*sta)->next->index == 1)
					ft_sa(sta);
				i++;
			}
			else
				fast_move(stb, sta, list_counter(*stb));
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

void	range_push(t_list **sta, t_list **stb, int arc)
{
	int		i;
	int		j;

	i = 30;
	j = 1;
	while (!(*stb) && !check_order(*sta))
	{
		push_to_b (sta, stb, arc, 22);
		push_to_a(sta, stb, arc);
	}
}
