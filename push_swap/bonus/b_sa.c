/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:52:32 by azabir            #+#    #+#             */
/*   Updated: 2022/04/17 01:52:42 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	b_sa(t_list **stack)
{
	int	data;

	if (*stack && (*stack)->next)
	{
		data = (*stack)->next->data;
		(*stack)->next->data = (*stack)->data;
		(*stack)->data = data;
		data = (*stack)->next->index;
		(*stack)->next->index = (*stack)->index;
		(*stack)->index = data;
	}
}

