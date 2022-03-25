/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:05:07 by azabir            #+#    #+#             */
/*   Updated: 2022/03/25 10:05:09 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rstack(t_list **stack)
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

void	ft_rr(t_list **sta, t_list **stb)
{
	if (*sta && *stb)
	{
		ft_rstack(sta);
		ft_rstack(stb);
		if ((*sta)->next || (*stb)->next)
			write (1, "rr\n", 3);
	}
}
