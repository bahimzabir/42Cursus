/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:53:13 by azabir            #+#    #+#             */
/*   Updated: 2022/04/17 01:53:33 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	b_swap(t_list **stack)
{
	int	data;

	if ((*stack) && (*stack)->next)
	{
		data = (*stack)->next->data;
		(*stack)->next->data = (*stack)->data;
		(*stack)->data = data;
		data = (*stack)->next->index;
		(*stack)->next->index = (*stack)->index;
		(*stack)->index = data;
	}	
}

void	b_ss(t_list **sta, t_list **stb)
{
	if ((*sta && (*sta)->next) || (*stb && (*stb)->next))
	{
		b_swap(sta);
		b_swap(stb);
	}
}
