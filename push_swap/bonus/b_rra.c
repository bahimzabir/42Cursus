/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_rra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:50:13 by azabir            #+#    #+#             */
/*   Updated: 2022/04/17 01:50:31 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	b_rra(t_list **sta)
{
	t_list	*temp1;
	t_list	*temp2;

	if (*sta && (*sta)->next)
	{
		temp1 = *sta;
		while (temp1->next != NULL)
		{
			temp2 = temp1;
			temp1 = temp1->next;
		}
		temp1->next = *sta;
		(*sta)->prev = temp1;
		temp1->prev = NULL;
		temp2->next = NULL;
		*sta = temp1;
	}
}
