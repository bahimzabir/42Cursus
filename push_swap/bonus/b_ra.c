/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ra.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:48:03 by azabir            #+#    #+#             */
/*   Updated: 2022/04/17 01:48:54 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../src/push_swap.h"

void	b_ra(t_list **sta)
{
	t_list	*temp1;
	t_list	*temp2;

	if (*sta && (*sta)->next)
	{
		temp1 = *sta;
		while (temp1->next != NULL)
			temp1 = temp1->next;
		temp2 = *sta;
		*sta = (*sta)->next;
		temp1->next = temp2;
		temp2->prev = temp1;
		temp2->next = NULL;
		(*sta)->prev = NULL;
	}
}
