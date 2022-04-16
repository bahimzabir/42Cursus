/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:07:42 by azabir            #+#    #+#             */
/*   Updated: 2022/03/25 12:07:44 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrstack(t_list **stack)
{
	t_list	*temp1;
	t_list	*temp2;

	if (*stack && (*stack)->next)
	{
		temp1 = *stack;
		while (temp1->next != NULL)
			temp1 = temp1->next;
		temp2 = temp1;
		temp2 = temp2->prev;
		temp2->next = NULL;
		temp1->next = *stack;
		temp1->prev = NULL;
		*stack = temp1;
	}
}

void	ft_rrr(t_list **sta, t_list **stb)
{
	if (*sta && *stb)
	{
		ft_rrstack(sta);
		ft_rrstack(stb);
		if ((*sta)->next || (*stb)->next)
			write (1, "rrr\n", 4);
	}
}
