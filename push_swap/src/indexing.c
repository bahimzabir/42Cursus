/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:17:17 by azabir            #+#    #+#             */
/*   Updated: 2022/03/26 17:17:19 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_list **stack, int arc)
{
	t_list	*temp;
	t_list	*holder;
	int		index;
	int		dep;

	index = 1;
	dep = 1;
	holder = *stack;
	while (holder)
	{
		temp = *stack;
		while (temp)
		{
			if (holder->data > temp->data)
				index++;
			else if (holder->data == temp->data)
				dep ++;
			temp = temp->next;
		}
		if (dep > arc)
			exit(1);
		holder->index = index;
		holder = holder->next;
		index = 1;
	}
}
