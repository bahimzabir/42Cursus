/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:04:56 by azabir            #+#    #+#             */
/*   Updated: 2022/03/25 10:04:59 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **sta)
{
	t_list	*temp1;
	t_list	*temp2;

	if (*sta)
	{
		temp1 = *sta;
		while (temp1->next != NULL)
			temp1 = temp1->next;
		temp2 = *sta;
		if ((*sta)->next)
			*sta = (*sta)->next;
		temp1->next = temp2;
		temp2->prev = temp1;
		temp2->next = NULL;
		write (1, "ra\n", 3);
	}
}
