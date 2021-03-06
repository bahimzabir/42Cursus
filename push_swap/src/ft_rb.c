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

void	ft_rb(t_list **stb)
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
		write (1, "rb\n", 3);
	}
}
