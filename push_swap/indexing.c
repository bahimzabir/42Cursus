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

	index = 1;
	holder = *stack;
	while (holder)
	{
		temp = *stack;
		while (temp)
		{
			if ((holder->data > temp->data))
			{
				if (holder->data == temp->data)
					exit(1);
				index++;
			}
			temp = temp->next;
		}
		holder->index = index;
		holder = holder->next;
		index = 1;
	}

}
