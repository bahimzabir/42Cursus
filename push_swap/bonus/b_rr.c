/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_rr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:49:40 by azabir            #+#    #+#             */
/*   Updated: 2022/04/17 01:50:03 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	b_rstack(t_list **stack)
{
	t_list	*temp1;
	t_list	*temp2;

	if (*stack && (*stack)->next)
	{
		temp1 = *stack;
		while (temp1->next != NULL)
			temp1 = temp1->next;
		temp2 = *stack;
		if ((*stack)->next)
			*stack = (*stack)->next;
		temp1->next = temp2;
		temp2->prev = temp1;
		temp2->next = NULL;
	}
}

void	b_rr(t_list **sta, t_list **stb)
{
	if (*sta && *stb)
	{
		b_rstack(sta);
		b_rstack(stb);
	}
}
