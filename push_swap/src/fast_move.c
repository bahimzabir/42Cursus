/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fats_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:55:08 by azabir            #+#    #+#             */
/*   Updated: 2022/04/04 17:00:36 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fast_move(t_list **stb, int index, int c)
{
	int		count;
	t_list	*temp;

	count = 1;
	temp = *stb;
	while (temp && temp->index != index)
	{
		temp = temp->next;
		count++;
	}
	if (count <= c / 2 + 1)
		while ((*stb) && (index != (*stb)->index))
			ft_rb(stb);
	else
		while ((*stb) && (*stb)->index != index)
			ft_rrb(stb);
}
