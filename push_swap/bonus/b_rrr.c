/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_rrr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:51:25 by azabir            #+#    #+#             */
/*   Updated: 2022/04/17 01:52:15 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	b_rrstack(t_list **stack)
{
	t_list	*temp1;
	t_list	*temp2;

	if (*stack && (*stack)->next)
	{
		temp1 = *stack;
		while (temp1->next != NULL)
		{
			temp2 = temp1;
			temp1 = temp1->next;
		}
		temp1->next = *stack;
		(*stack)->prev = temp1;
		temp1->prev = NULL;
		temp2->next = NULL;
		*stack = temp1;
	}
}

void	b_rrr(t_list **sta, t_list **stb)
{
	if (*sta && *stb)
	{
		b_rrstack(sta);
		b_rrstack(stb);
	}
}
