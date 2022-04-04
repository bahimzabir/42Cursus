/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:08:14 by azabir            #+#    #+#             */
/*   Updated: 2022/04/04 17:08:49 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	basic_push(t_list **sta, t_list **stb, int arc)
{
	int		i;
	int		j;
	t_list	*temp;

	temp = *sta;
	i = 1;
	j = 0;
	while (i <= arc)
	{

		while (((*sta)->index != i) && (check_order(*sta) == 0))
			do_move(sta, stb, arc, i);
		if ((i == arc || check_order(*sta) == 1) && !(*stb))
			break;
		if (check_order(*sta) == 0)
			ft_pb(sta, stb);
		i++;
		if (i == arc && check_order(*sta) == 1)
			while (i >= 1)
			{
				ft_pa(sta, stb);
				i--;
			}
		if (i == 0)
			break;
	}
}

