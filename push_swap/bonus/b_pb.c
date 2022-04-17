/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:54:07 by azabir            #+#    #+#             */
/*   Updated: 2022/04/17 01:54:25 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	b_pb(t_list **sta, t_list **stb)
{
	t_list	*temp;

	if (*sta != NULL)
	{
		temp = *sta;
		if ((*sta)->next)
		{
			*sta = (*sta)->next;
			(*sta)->prev = NULL;
		}
		else
			*sta = NULL;
		temp->next = *stb;
		*stb = temp;
	}
}
