/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:48:13 by azabir            #+#    #+#             */
/*   Updated: 2022/04/04 16:49:02 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_range(t_list *list, int i, int arc)
{
	 t_list	*temp;

	 temp = list;
	 while (temp)
	 {
		 if (temp->index >= arc / 2 - i && temp->index <= arc / 2 + i - 1)
		 	return (1);
		temp = temp->next;
	 }
	 return (0);
}
