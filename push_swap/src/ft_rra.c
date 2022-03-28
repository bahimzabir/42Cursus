/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:07:24 by azabir            #+#    #+#             */
/*   Updated: 2022/03/25 12:07:28 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **sta)
{
	t_list	*temp1;
	t_list	*temp2;

	if (*sta && (*sta)->next)
	{
		temp1 = *sta;
		while (temp1->next != NULL)
			temp1 = temp1->next;
		temp2 = temp1;
		temp2 = temp2->prev;
		temp2->next = NULL;
		temp1->next = *sta;
		(*sta)->prev = temp1;
		temp1->prev = NULL;
		*sta = temp1;
		write (1, "rra\n", 4);
	}
}
