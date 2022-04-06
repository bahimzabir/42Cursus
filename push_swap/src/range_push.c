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
		else if ((*sta)->index <= i)
			{
				ft_pb(sta, stb);
				ft_rb(stb);
			}
		else
			ft_ra(sta);
		if ((*stb) && (*stb)->index <= arc / 2)
			ft_rb(stb);
		if (!check_range(*sta, i, arc))
		{
			i = i + 15;
			if (i >= arc / 2)
				i = arc / 2;
			j = 0;
		}
	}
}

void	push_to_a(t_list **sta, t_list **stb)
{
	while (*stb)
		{
			if ((*sta)->index - (*stb)->index == 1)
				ft_pa(sta, stb);
			else
				fast_move(stb, sta, list_counter(*stb));
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
		push_to_b (sta, stb, arc, 30);
		push_to_a(sta, stb);
	}
}

