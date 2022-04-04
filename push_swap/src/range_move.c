/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:02:18 by azabir            #+#    #+#             */
/*   Updated: 2022/04/04 17:02:53 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	range_move(t_list **sta, int i)
{
	int		count;
	int		size;
	t_list	*temp;

	temp = *sta;
	count = 0;
	size = list_counter(temp);
	if ((*sta)->next && (*sta)->index - (*sta)->next->index == 1)
		ft_sa(sta);
	while (temp->index <= i)
	{
		temp = temp->next;
		count++;
	}
	if (!check_order(*sta))
	{
		if (count <= size/2 + 1)
			ft_ra(sta);
		else
			ft_rra(sta);
	}

}

