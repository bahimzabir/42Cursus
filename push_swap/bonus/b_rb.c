/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_rb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:49:04 by azabir            #+#    #+#             */
/*   Updated: 2022/04/17 01:49:34 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	b_rb(t_list **stb)
{
	t_list	*temp1;
	t_list	*temp2;

	if (*stb && (*stb)->next)
	{
		temp1 = *stb;
		while (temp1->next != NULL)
			temp1 = temp1->next;
		temp2 = *stb;
		*stb = (*stb)->next;
		temp1->next = temp2;
		temp2->prev = temp1;
		temp2->next = NULL;
		(*stb)->prev = NULL;
	}
}

