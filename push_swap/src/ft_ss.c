/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:58:23 by azabir            #+#    #+#             */
/*   Updated: 2022/03/24 15:58:25 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
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

void	ft_ss(t_list **sta, t_list **stb)
{
	if ((*sta && (*sta)->next) || (*stb && (*stb)->next))
	{
		ft_swap(sta);
		ft_swap(stb);
		write (1, "ss\n", 3);
	}
}
