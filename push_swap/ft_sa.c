/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:09:14 by azabir            #+#    #+#             */
/*   Updated: 2022/03/24 15:36:43 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list *stack)
{
	int	data;

	data = stack->next->data;
	stack->next->data = stack->data;
	stack->data = data;
	write (1, "sa\n", 3);
}
