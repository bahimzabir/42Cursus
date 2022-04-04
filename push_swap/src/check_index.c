/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:18:33 by azabir            #+#    #+#             */
/*   Updated: 2022/04/04 17:19:19 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_index(t_list *list, int i)
{
	t_list	*temp;

	temp = list;
	while (temp)
	{
		if (temp->index <= i)
			return (1);
		temp = temp->next;
	}
	return (0);
}
