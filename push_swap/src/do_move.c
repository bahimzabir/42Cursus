/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:49:30 by azabir            #+#    #+#             */
/*   Updated: 2022/03/28 15:49:35 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_move(t_list **sta, int	arc, int i)
{
	int		index;
	int		count;
	t_list	*temp;

	temp = *sta;
	count = 1;
	index =  temp->index + 1;
	if ((temp->index - temp->next->index) > 0)
		ft_sa(sta);
	while (temp->index != i)
	{
		temp = temp->next;
		count++;
	}
	if (count >= (arc / 2))
		while ((*sta)->index != i)
			ft_rra(sta);
	else
		while ((*sta)->index != i)
			ft_ra(sta);
}
