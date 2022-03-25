/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:27:52 by azabir            #+#    #+#             */
/*   Updated: 2022/03/24 15:32:25 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_list **stack)
{
	int	data;

	if ((*stack)->data && (*stack)->next->data)
	{
		data = (*stack)->next->data;
		(*stack)->next->data = (*stack)->data;
		(*stack)->data = data;
		write (1, "sb\n", 3);
	}	
}
