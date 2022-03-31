/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:15:36 by azabir            #+#    #+#             */
/*   Updated: 2022/03/25 21:15:41 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_list	*stack)
{
	t_list	*temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->index - temp->next->index == -1)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}
