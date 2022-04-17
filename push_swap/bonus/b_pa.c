/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:53:43 by azabir            #+#    #+#             */
/*   Updated: 2022/04/17 01:53:59 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	b_pa(t_list **sta, t_list **stb)
{
	t_list	*temp;

	if (*stb != NULL)
	{
		temp = *stb;
		if ((*stb)->next)
		{
			*stb = (*stb)->next;
			(*stb)->prev = NULL;
		}
		else
			*stb = NULL;
		temp->next = *sta;
		temp->prev = NULL;
		*sta = temp;
	}
}
