/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:31:52 by azabir            #+#    #+#             */
/*   Updated: 2022/03/24 16:31:54 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list **sta, t_list **stb)
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
		if (*sta)
			(*sta)->prev = temp;
		*sta = temp;
	}
}
