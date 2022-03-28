/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:06:59 by azabir            #+#    #+#             */
/*   Updated: 2022/03/28 00:07:00 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_listlen(t_list *list)
{
	int		len;
	t_list	*temp;

	temp = list;
	len = 0;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}
