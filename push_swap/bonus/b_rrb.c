/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_rrb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:50:37 by azabir            #+#    #+#             */
/*   Updated: 2022/04/17 01:51:04 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	b_rrb(t_list **stb)
{
	t_list	*temp1;
	t_list	*temp2;

	if (*stb && (*stb)->next)
	{
		temp1 = *stb;
		while (temp1->next != NULL)
		{
			temp2 = temp1;
			temp1 = temp1->next;
		}
		temp1->next = *stb;
		(*stb)->prev = temp1;
		temp1->prev = NULL;
		temp2->next = NULL;
		*stb = temp1;
	}
}
