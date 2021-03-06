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

void	push_to_b(t_list **sta, t_list **stb, int arc, int i)
{
	float	j;

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

int	stack_organizer(t_list **stb, t_list **sta, int i, int j)
{
	if ((*stb) && i - (*stb)->index >= 45 && !j)
	{
		while (list_end(*stb) >= 90)
			ft_rrb(stb);
		while (j <= 249)
		{
			swap_move(sta, stb);
			if ((*stb) && (*stb)->index >= 251)
			{
				ft_pa(sta, stb);
					j++;
			}
			else
				ft_rb(stb);
			if (!check_custom_range(*stb, 251))
				break ;
		}
		while (!check_order(*sta))
		{
			ft_pb(sta, stb);
			swap_move(sta, stb);
		}
	}
	return (j);
}

void	push_to_a(t_list **sta, t_list **stb)
{
	int	i;
	int	j;
	int	index;

	i = 500;
	j = 0;
	while (*stb)
	{
		if (check_order(*sta))
			index = (*sta)->index - 1;
		if ((*stb)->index == index || ((*stb)->index == index - 1
				&& check_order(*sta)))
		{
			ft_pa(sta, stb);
			swap_move(sta, stb);
			i--;
		}
		else
			fast_move(stb, index, list_counter(*stb));
		j = stack_organizer(stb, sta, i, j);
	}
}

void	range_push(t_list **sta, t_list **stb, int arc)
{
	int		i;
	int		j;

	i = 30;
	j = 1;
	push_to_b (sta, stb, arc, 22);
	push_to_a(sta, stb);
}
