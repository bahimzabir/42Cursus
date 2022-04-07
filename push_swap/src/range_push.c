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
			printf("%d ", tmp->data);
			tmp = tmp->next;
		}
	}
	printf("\n-----------------\n");
}

void	push_to_b(t_list **sta, t_list **stb, int arc, int i)
{
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
			i = i + 22;
		if (i >= arc / 2)
				i = arc / 2;
	}
}

int	check_custom_range(t_list *list, int a, int b)
{
	 t_list	*temp;

	 temp = list;
	 while (temp)
	 {
		 if (temp->index >= b && temp->index <= a)
		 {
			//write (1, "HERE2\n", 6);
		 	return (1);
		 }
		temp = temp->next;
	 }
	 return (0);
}


void	push_to_a(t_list **sta, t_list **stb, int arc)
{
	int	i;

	i = 1;
	arc = 1;
	while (*stb)
		{
			if ((*sta)->index - (*stb)->index == 1)
				ft_pa(sta, stb);
			else
				fast_move(stb, sta, list_counter(*stb));
			/*else
			{
				while (check_custom_range(*stb, arc / 4, arc / 2))
				{
					if ((*stb) && (*stb)->index >= arc / 4 && (*stb)->index <= arc / 2)
						ft_pa(sta, stb);
					else
						ft_rrb(stb);
				}
				i = 0;
			}
				while (!check_order(*sta))
					ft_pb(sta, stb);*/
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

