/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:51:23 by azabir            #+#    #+#             */
/*   Updated: 2022/04/04 16:51:57 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_end(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp->next)
		temp = temp->next;
	return (temp->index);
}
