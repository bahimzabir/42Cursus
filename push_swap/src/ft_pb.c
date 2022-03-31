/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:22:20 by azabir            #+#    #+#             */
/*   Updated: 2022/03/24 20:22:22 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_list **sta, t_list **stb)
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
		write (1, "pb\n", 3);
	}
}
